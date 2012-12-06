#if !defined (RULE_H)
#define RULE_H

#include <string>
#include <array>
#include <list>
#include <regex>

#include "Request.h"

namespace REST {

class Rule
{
	enum BodyParamType {
		JSON 	= 1,
		FORM 	= 2,
		ANY 	= 3
	};
};
private:
	// Does this rule match the given http request?
	//
	int 					request_methods;
	boolean					secure_only;
	std::regex 				regex;

	// If the rule matches, then map the parameters given
	// in the http request to our local variables.
	//
	std::array<std::string>			regex_param_map;
	std::map<std::string,std::string>	get_param_map;
	std::map<std::string,std::string>	cookie_param_map;
	std::map<std::string,std::string>	body_param_map;
	BodyParamType				body_param_type;

	// If this rule matches, but there are still unmatched
	// chars in the request path, then repeat the matching
	// process with the children.
	//
	std::list<Rule> 			children;
};

} // namespace REST

#endif // !defined (RULE_H)
