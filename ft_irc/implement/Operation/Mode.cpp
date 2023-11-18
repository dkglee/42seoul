#include "../../header/Mode.hpp"

void ModeOperation::setMode(char c, std::string op) {
	this->mode = c;
	this->operand = op;
}

ModeOperation::~ModeOperation() {}
