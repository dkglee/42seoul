#ifndef MODE_HPP
# define MODE_HPP

# include "IOperation.hpp"

class ModeOperation : public IOperation {
private:
	char mode;
	std::string operand;
public:
	void setMode(char c, std::string op = "");
	virtual void runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd);
	virtual ~ModeOperation();
};

#endif
