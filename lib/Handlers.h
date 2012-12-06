#if !defined (HANDLERS_H)
#define HANDLERS_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <string>
#include <map>

#include "Request.h"

namespace REST {



void registerFactory(
	Method method,
	std::string& path, 
	Poco::Net::HTTPRequestHandlerFactory *factory
);

Poco::Net::HTTPRequestHandlerFactory * findFactory(std::string& path);

} // namespace REST

#endif // !defined (HANDLERS_H)
