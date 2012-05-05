#include <Poco/Util/ServerApplication.h>

#include "Configure.h"

#include "Server.h"

using Poco::Util::ServerApplication;

class App: public Poco::Util::ServerApplication
{
public:
	App()
	{
	}

	~App()
	{
	}

protected:
	int 
	main(const std::vector<std::string>& args)
	{
		REST::Server srv(SERVER_ADDRESS);

		srv.start();
		waitForTerminationRequest();
		srv.stop();

		return Application::EXIT_OK;
	}
};

int
main(int argc, char** argv)
{
	App app;
	return app.run(argc, argv);
}

