#if !defined (ACTION_H)
#define ACTION_H

#include <string>
#include <map>
#include <regex>

namespace REST {

class Action
{
public:
	class Param {
	private:
		std::regex		constraint;
		bool			required;
		std::string		def;
	};
	
private:
	std::map<std::string,Param>	params;
	
};

} // namespace REST

#endif // !defined (ACTION_H)
