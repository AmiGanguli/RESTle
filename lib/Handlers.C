#include "Handlers.h"

typedef std::map<std::string, Poco::Net::HTTPRequestHandlerFactory *> MapType;

static MapType * 
factories()
{
	static std::map<std::string, Poco::Net::HTTPRequestHandlerFactory *> map;

	return &map;
}

void 
REST::registerFactory(std::string& path, Poco::Net::HTTPRequestHandlerFactory *factory)
{
	(*(factories()))[path] = factory;
}

Poco::Net::HTTPRequestHandlerFactory *
REST::findFactory(std::string& path)
{
	MapType::iterator i = factories()->find(path);
	if (i == factories()->end()) {
		return 0;
	}
	return i->second;
}

