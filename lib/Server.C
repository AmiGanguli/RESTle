#include "Server.h"

#include <Poco/URI.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerParams.h>

#include <iostream>

class RequestHandler: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(
		Poco::Net::HTTPServerRequest& request,
		Poco::Net::HTTPServerResponse& response
	)
	{
	}
};

class RequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
public:
	Poco::Net::HTTPRequestHandler* 
	createRequestHandler(const Poco::Net::HTTPServerRequest& request)
	{
		Poco::URI uri(request.getURI());
		return new RequestHandler();
//		if (uri.getPath() == "/image") {
//			return new RenderRequestHandler(ac_, Request::PNG);
//		} else if (uri.getPath() == "/pdf") {
//			return new RenderRequestHandler(ac_, Request::PDF);
//		} 
//		return 0;
	}
};

class REST::Server::Pimpl {
public:
	Poco::Net::SocketAddress socket_address_;
	Poco::Net::ServerSocket server_socket_;
	Poco::Net::HTTPServer poco_server_;

	Pimpl(const char *ip_address) :
		socket_address_(ip_address),
		server_socket_(socket_address_) ,
		poco_server_(
			new RequestHandlerFactory(), 
			server_socket_,
			new Poco::Net::HTTPServerParams()
		)
	{
	}

	void
	start()
	{
		poco_server_.start();
	}

	void
	stop()
	{
		poco_server_.stop();
	}
};

REST::Server::Server(const char *server_address) : 
	pimpl_(new Pimpl(server_address))
{
}

void 
REST::Server::start()
{
	pimpl_->start();
}

void
REST::Server::stop()
{
	pimpl_->stop();
}

