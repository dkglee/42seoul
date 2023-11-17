#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperation.hpp"
# include <string>

class Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size) = 0;
	virtual ~Creator() = 0;
};

class AuthCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~AuthCreator();
};

class OpCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size) = 0;
	virtual ~OpCreator() = 0;
};

class OpKickCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~OpKickCreator();
};

class OpInviteCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~OpInviteCreator();
};

class OpTopicCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~OpTopicCreator();
};

class OpModeCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~OpModeCreator();
};

class JoinCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~JoinCreator();
};

class MessageCreator : public Creator {
public:
	virtual IOperation* factoryMethod(char* buf, int buf_size);
	virtual ~MessageCreator();
};

#endif
