#include "../../header/Exception.hpp"

MyException::MyException(ErrorCode errNum) : err_no(errNum) {}

ErrorCode MyException::getErrCode() {
	return this->err_no;
}

ParseException::ParseException(ErrorCode errNum, std::string what) : MyException(errNum), str(what) {}

const char* ParseException::what() const throw() {
	return str.c_str();
}

ExitException::ExitException(ErrorCode errNum, std::string what) : MyException(errNum), str(what) {}

const char* ExitException::what() const throw() {
	return str.c_str();
}

OperationException::OperationException(ErrorCode errNum, std::string what) : MyException(errNum), str(what) {}

const char* OperationException::what() const throw() {
	return str.c_str();
}

