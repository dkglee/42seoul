#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>
# include <string>
// # include "Socket.hpp"

enum ErrorCode {
	PARSEEXCEPTION,
	EXITEXCEPTION,
	OPERATIONEXCEPTION,
};

class MyException {
private:
	ErrorCode err_no;
public:
	MyException(ErrorCode);
	virtual const char* what() const throw() = 0;
	ErrorCode getErrCode();
};

class ParseException : public MyException {
private:
	std::string str;
public:
	ParseException(ErrorCode, std::string);
	virtual const char* what() const throw();
};

class ExitException : public MyException {
private:
	std::string str;
public:
	ExitException(ErrorCode, std::string);
	virtual const char* what() const throw();
};

class OperationException : public MyException {
private:
	std::string str;
public:
	OperationException(ErrorCode, std::string);
	virtual const char* what() const throw();
};

#endif
