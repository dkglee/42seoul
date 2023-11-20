#ifndef AUTHOPERATION_HPP
# define AUTHOPERATION_HPP

# include "IOperation.hpp"

class AuthOperation;

typedef std::string AuthOperation::*AuthPtr;

class AuthOperation : public IOperation {
private:
	bool flag;
	std::string password;
	std::string userName;
	std::string nickName;
public:
	void setValue(std::string val, int offset);
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int pw);
	virtual ~AuthOperation();
};

#endif
