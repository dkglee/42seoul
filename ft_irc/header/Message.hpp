#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include "IOperation.hpp"

class MessageOperation : public IOperation {
private:
	std::string msg;
public:
	void setMessage(std::string);
	virtual void runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd);
	virtual ~MessageOperation();
};

#endif
