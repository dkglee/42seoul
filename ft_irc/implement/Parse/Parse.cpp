#include "../../header/Parse.hpp"
#include "../../header/Exception.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

std::vector<std::string> Parse::parseOperationArguments() {
	std::string temp(buf);
	std::istringstream iss(temp);
	
	std::string temp_buf;
	char delemiter = ' ';
	std::vector<std::string> ret;
	while (getline(iss, temp_buf, ' ')) {
		ret.push_back(temp_buf);
	}
	return ret;
}

IOperation* Parse::swithParseOperation(std::vector<std::string>& parsed) {
	// 조건 분기문 최적화를 할 필요가 있을듯
	IOperation* ret;
	Creator* create_tool;
	if (parsed.size() < 2) {
		throw ParseException(PARSEEXCEPTION, "Wrong Args lists try again.");
	}
	if (!parsed[0].compare("/kick")) {
		create_tool = new OpKickCreator();
	} else if (!parsed[0].compare("/invite")) {
		create_tool = new OpInviteCreator();
	} else if (!parsed[0].compare("/topic")) {
		create_tool = new OpTopicCreator();
	} else if (!parsed[0].compare("/mode")) {
		create_tool = new OpModeCreator();
	} else if (!parsed[0].compare("/join")) {
		create_tool = new JoinCreator();
	} else {
		throw ParseException(PARSEEXCEPTION, "There is No Such Operation.");
	}
	try {
		ret = create_tool->factoryMethod(parsed);
	} catch (MyException&) {
		delete create_tool;
		throw;
	}
	return ret;
}

IOperation* Parse::parseBuf(int fd, r_list& ru_list, b_list& bk_list) {
	int strlen = sock_tool->readBuff(fd, buf);
	if (strlen == 0) {
		throw ExitException(EXITEXCEPTION, "Client exits from the Server.");
	}
	std::vector<std::string> parsed = parseOperationArguments();
	parsed[parsed.size() - 1].erase(parsed[parsed.size() - 1].find('\n'));
	IOperation* ret;
	try {
		if (ru_list.find(fd) == ru_list.end()) {
			Creator* create_tool = new AuthCreator();
			ret = create_tool->factoryMethod(parsed);
			delete create_tool;
		}
		else {
			if (buf[0] == '/')
				ret = swithParseOperation(parsed);
			else {
				Creator* create_tool = new MessageCreator();
				ret = create_tool->factoryMethod(parsed);
				delete create_tool;
			}
		}
	} catch (MyException&) {
		throw ;
	}
	std::memset(this->buf, 0, sizeof(this->buf));
	return ret;
}
