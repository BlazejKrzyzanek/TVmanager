#include "stdafx.h"
#include "MyException.h"

MyException::MyException(string message) {
	this->message = message;
}

string MyException::getMessage() {
	return this->message;
}