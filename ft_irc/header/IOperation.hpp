#ifndef IOPERATION_HPP
# define IOPERATION_HPP

# include <map>
# include <string>
# include "User.hpp"
# include "Channel.hpp"
# include "Socket.hpp"

typedef std::map<int, User> r_list;
typedef std::map<std::string, User> b_list;

class IOperation {
protected:
	Socket* sock_tool;
public:
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int pw) = 0;
	virtual ~IOperation();
};

#endif
