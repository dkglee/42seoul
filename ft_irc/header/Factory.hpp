#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperation.hpp"
# include "Stringtool.hpp"
# include <string>

class Creator {
public:
	StringTool* s_tool;
	virtual IOperation* factoryMethod(std::vector<std::string>&) = 0;
	virtual ~Creator();
};

class AuthCreator : public Creator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~AuthCreator();
};

class OpCreator : public Creator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&) = 0;
	virtual ~OpCreator();
};

class OpKickCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~OpKickCreator();
};

class OpInviteCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~OpInviteCreator();
};

class OpTopicCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~OpTopicCreator();
};

class OpModeCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~OpModeCreator();
};

class JoinCreator : public OpCreator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~JoinCreator();
};

class MessageCreator : public Creator {
public:
	virtual IOperation* factoryMethod(std::vector<std::string>&);
	virtual ~MessageCreator();
};

#endif
