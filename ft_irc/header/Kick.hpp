#ifndef KICK_HPP
# define KICK_HPP

# include "IOperation.hpp"

class KickOperation : public IOperation {
private:
	std::string nickname;
public:
	void setNickname(std::string);
	virtual void runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd);
	virtual ~KickOperation();
};

#endif
