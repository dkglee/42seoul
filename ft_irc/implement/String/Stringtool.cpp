#include "../../header/Stringtool.hpp"

std::string StringTool::makeString(std::vector<std::string>& strings) {
	std::string ret;
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		ret += *it;
		ret += ' ';
	}
	ret.erase(ret.end() - 1);
	return ret;
}
