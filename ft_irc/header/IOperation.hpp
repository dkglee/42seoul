#ifndef IOPERATION_HPP
# define IOPERATION_HPP

# include <map>
# include <string>
# include "User.hpp"
# include "Channel.hpp"

class IOperation {
public:
	virtual void runOperation(Channel* chs, std::map<int, User>& user_list, int fd);
	virtual ~IOperation();
};

#endif
