#ifndef PARSE_HPP
# define PARSE_HPP

# define BUFF_SIZE 1500

# include "IOperation.hpp"
# include "User.hpp"
# include <map>
# include <string>

class Parse {
private:
	char buf[BUFF_SIZE];
public:
	IOperation* parseBuf(int, std::map<int, User>&, std::map<std::string, User>&);
};

#endif
