#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include "IOperation.hpp"

class MessageOperation : public IOperation {
private:
	std::string msg;
	void broadcast(Channel*, r_list::iterator);
public:
	void setMessage(std::string);
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key);
	virtual ~MessageOperation();
};

#endif
