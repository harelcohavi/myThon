#include "NameErrorException.h"
#include <string>

NameErrorExcaption::NameErrorExcaption(std::string name)
	: _name(name)
{
}

const char* NameErrorExcaption::what() const
{
	std::string str = "NameError : name" + this->_name + "is not defined";
	return str.c_str();
}