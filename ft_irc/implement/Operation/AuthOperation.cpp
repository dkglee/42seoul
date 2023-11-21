#include "../../header/AuthOperation.hpp"
#include <cstring>
#include <map>
#include "../../header/User.hpp"
#include <iostream>

void AuthOperation::setValue(std::string pw, std::string un, std::string ni) {
	password = pw;
	userName = un;
	nickName = ni;
}

// 어떤 기능이 와야 하는가?
// 패스워드 인증 -> 닉네임과 유저 네임 세팅 -> 백업 페이지에 등록(마지막 구현 예정) -> 공홈으로 채널 세팅 후 종료
int AuthOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int pw) {
	std::cout << password << ' ' << userName << ' ' << nickName << std::endl;

	if (atoi(this->password.c_str()) != pw) {
		// err
	}
	b_list::iterator it = bu_list.find(userName);
	if (it != bu_list.end()) {
		// load User from Back
	} else {
		// set new User and save in Back
		User temp;
		temp.setNewUser(false, userName, nickName);
		ru_list.insert({fd, temp});
		r_list::iterator it = ru_list.find(fd);
		// bu_list.insert({userName, it->second});
	}
	chs[0].addUser(fd, userName);
	std::string sendMsg= "Welcome ";
	sendMsg = sendMsg + userName;
	sendMsg = sendMsg + "\n";
	send(fd, sendMsg.c_str(), strlen(sendMsg.c_str()), 0);
	return 0;
}

AuthOperation::~AuthOperation() {}
