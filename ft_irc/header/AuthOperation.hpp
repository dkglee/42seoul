#ifndef AUTHOPERATION_HPP
# define AUTHOPERATION_HPP

# include "IOperation.hpp"

class AuthOperation : public IOperation {
private:
	bool flag;
	std::string password;
	std::string userName;
	std::string nickName;
	std::string channel;
public:
	void setValue(std::string val, int flag);
	virtual void runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd);
	virtual ~AuthOperation();
};

#endif
