#ifndef PARSE_HPP
# define PARSE_HPP

# define BUFF_SIZE 1500

# include "IOperation.hpp"
# include "User.hpp"
# include <map>
# include <string>

typedef std::map<int, User> r_list;
typedef std::map<std::string, User> b_list;

class Parse {
private:
	Socket* sock_tool;
	char buf[BUFF_SIZE];
public:
	IOperation* parseBuf(int, r_list&, b_list&);
};

#endif
