#include "../../header/AuthOperation.hpp"
#include <cstring>
#include <map>
#include "../../header/User.hpp"

void AuthOperation::setValue(std::string val, int offset) {
	AuthPtr arr[3] = {&AuthOperation::password, &AuthOperation::userName, &AuthOperation::nickName};
	(this->*arr[offset]) = val;
}

// 어떤 기능이 와야 하는가?
// 패스워드 인증 -> 닉네임과 유저 네임 세팅 -> 백업 페이지에 등록(마지막 구현 예정) -> 공홈으로 채널 세팅 후 종료
int AuthOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int pw) {
	if (atoi(this->password.c_str()) != pw) {
		// err
	}
	b_list::iterator it = bu_list.find(userName);
	if (it != bu_list.end()) {
		// load User from Back
	} else {
		// set new User and save in Back
		r_list::iterator it = ru_list.find(fd);
		it->second.setNewUser(false, userName, nickName);
		bu_list.insert({userName, it->second});
	}
	chs->addUser(fd, userName);
	std::string sendMsg= "Welcome";
	sendMsg += nickName;
	send(fd, sendMsg.c_str(), strlen(sendMsg.c_str()), 0);
}

AuthOperation::~AuthOperation() {}
