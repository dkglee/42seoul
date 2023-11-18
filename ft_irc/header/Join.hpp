#ifndef JOIN_HPP
# define JOIN_HPP

# include "IOperation.hpp"

class JoinOperation : public IOperation {
private:
	std::string channel;
	std::string key;
public:
	void setJoin(std::string chn, std::string key);
	virtual void runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd);
	virtual ~JoinOperation();
};

#endif
