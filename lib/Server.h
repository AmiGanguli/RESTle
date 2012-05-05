#if !defined (SERVER_H)
#define SERVER_H

#include <memory>

namespace REST
{

class Server {
public:
	Server(const char *server_address);

	void start();
	void stop();

protected:
	class Pimpl;
	std::auto_ptr<Pimpl> pimpl_;
};

} // HTTP

#endif // !defined (SERVER_H)
 
