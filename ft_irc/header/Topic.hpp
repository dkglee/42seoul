#ifndef TOPIC_HPP
# define TOPIC_HPP

# include "IOperation.hpp"

class TopicOperation : public IOperation {
private:
	std::string topic;
public:
	void setTopic(std::string);
	virtual int runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key);
	virtual ~TopicOperation();
};

#endif
