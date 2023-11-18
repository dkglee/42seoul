#include "../../header/Join.hpp"

void JoinOperation::setJoin(std::string chn, std::string key) {
	this->channel = chn;
	this->key = key;
}

JoinOperation::~JoinOperation() {}
