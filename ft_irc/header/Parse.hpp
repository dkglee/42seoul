#ifndef PARSE_HPP
# define PARSE_HPP

# define BUFF_SIZE 15000

# include "IOperation.hpp"
# include "User.hpp"
# include "Factory.hpp"
# include <map>
# include <string>

typedef std::map<int, User> r_list;
typedef std::map<std::string, User> b_list;

// typedef IOperation* (Creator::*FuncArr)(char*, int);

class Parse {
private:
	Socket* sock_tool;
	char buf[BUFF_SIZE];
	IOperation* swithParseOperation(std::vector<std::string>&);
	std::vector<std::string> parseOperationArguments();
public:
	IOperation* parseBuf(int, r_list&, b_list&);
};

#endif
