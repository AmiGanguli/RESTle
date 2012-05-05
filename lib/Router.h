#if !defined (ROUTER_H)
#define ROUTER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Poco/Net/HTTPRequestHandlerFactory.h>

namespace restle {

using Poco::Net;

class Router {
public:
	typedef std::vector<std::string> Segments;
	void addRoute(std::string route, HTTPRequestHandlerFactory *factory);
	HTTPRequestHandlerFactory *resolveRoute(Segments &segments);

private:
	class Segment {
	public:
		Segment(std::string& seg_) 
			: seg(seg_), factory(0)
		{}

		void
		setFactory(HTTPRequestHandlerFactory *factory_) 
		{
			factory = factory_;
		}

		void 
		addChild(std::string& seg_, Segment *child_)
		{
			children[seg_] = child_;
		}

		void
		addRoute(
			Segments segments_,
			Segments::iterator current_, 
			HTTPRequestHandlerFactory *factory
		)
		{
			if (
		}
		 
	private:
		std::string seg;
		std::map<Segment*> children;
		HTTPRequestHandlerFactory *factory;
	};
};

}

#endif // !defined (ROUTER_H)
