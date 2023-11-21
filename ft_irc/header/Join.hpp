#ifndef JOIN_HPP
# define JOIN_HPP

# include "IOperation.hpp"

class JoinOperation : public IOperation {
private:
	std::string channel;
	std::string key;
	bool authUser(Channel*, r_list::iterator);
	void broadcast(Channel*, r_list::iterator, int);
public:
	void setJoin(std::string chn, std::string key);
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key);
	virtual ~JoinOperation();
};

#endif
