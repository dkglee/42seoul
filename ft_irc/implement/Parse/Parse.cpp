#include "../../header/Parse.hpp"
#include <iostream>
#include <sstream>

IOperation* Parse::swithParseOperation() {
	// 조건 분기문 최적화를 할 필요가 있을듯
	std::string temp(buf);
	std::istringstream iss(temp);
	
	std::string temp_buf;
	char delemiter = ' ';
	getline(iss, temp_buf, ' ');

	IOperation* ret;
	Creator* create_tool;
	if (temp_buf.compare("/kick")) {
		create_tool = new OpKickCreator();
	} else if (temp_buf.compare("/invite")) {
		create_tool = new OpInviteCreator();
	} else if (temp_buf.compare("/topic")) {
		create_tool = new OpTopicCreator();
	} else if (temp_buf.compare("/mode")) {
		create_tool = new OpModeCreator();
	} else if (temp_buf.compare("/join")) {
		create_tool = new JoinCreator();
	}
	ret = create_tool->factoryMethod(buf, BUFF_SIZE);
	delete create_tool;
	return ret;
}

IOperation* Parse::parseBuf(int fd, r_list& ru_list, b_list& bk_list) {
	int strlen = sock_tool->readBuff(fd, buf);
	IOperation* ret;
	if (ru_list.find(fd) == ru_list.end()) {
		Creator* creat_tool = new AuthCreator();
		ret = creat_tool->factoryMethod(buf, BUFF_SIZE);
		delete creat_tool;
	} else {
		if (buf[0] == '/')
			ret = swithParseOperation();
		else {
			Creator* creat_tool = new MessageCreator();
			ret = creat_tool->factoryMethod(buf, BUFF_SIZE);
			delete creat_tool;
		}
	}
	return ret;
}
