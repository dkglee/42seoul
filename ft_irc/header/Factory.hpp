#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperation.hpp"

class Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size) = 0;
	virtual ~Creator() = 0;
};

class AuthCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class OpCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class OpKickCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class OpInviteCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class OpTopicCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class OpModeCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class JoinCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

class MessageCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
};

#endif
