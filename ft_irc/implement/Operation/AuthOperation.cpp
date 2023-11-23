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

	// creator에서 처리하면 된다.
	// if (password.size() != 0 || userName.size() != 0 || nickName.size() != 0) {
	// 	send(fd, "Please keep this form. == Password(space)Username(space)Nickname.\n", strlen("Please keep this form. == Password(space)Username(space)Nickname.\n"), 0);
	// 	return -1;
	// }
	if (atoi(this->password.c_str()) != pw) {
		send(fd, "Password is wrong, Please try again.\n", strlen("Password is wrong, Please try again.\n"), 0);
		return -1;
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
	chs[0].addUser(fd, nickName);
	std::string sendMsg= "Welcome ";
	sendMsg = sendMsg + nickName;
	sendMsg = sendMsg + "\n";
	send(fd, sendMsg.c_str(), strlen(sendMsg.c_str()), 0);
	return 0;
}

AuthOperation::~AuthOperation() {}
