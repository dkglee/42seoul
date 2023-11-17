#include "../../header/Parse.hpp"

IOperation* Parse::parseBuf(int fd, r_list& ru_list, b_list& bk_list) {
	int strlen = sock_tool->readBuff(fd, buf);
	if (ru_list.find(fd) == ru_list.end()) {
		
	} else {

	}
}
