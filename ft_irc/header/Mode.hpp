#ifndef MODE_HPP
# define MODE_HPP

# include "IOperation.hpp"

class ModeOperation : public IOperation {
private:
	char mode;
	std::string operand;
	void inviteMode(r_list::iterator, Channel* chs);
	void topicMode(r_list::iterator, Channel* chs);
	void keyMode(r_list::iterator, Channel* chs);
	void limitMode(r_list::iterator, Channel* chs);
	void operatorMode(r_list::iterator, Channel* chs, r_list&, b_list&);
public:
	void setMode(char c, std::string op = "");
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key);
	virtual ~ModeOperation();
};

#endif
