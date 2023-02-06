#include "Integer.h"
#include <string>

Integer::Integer(int value)
	: _num(value) ,Type()
{
}

Integer::~Integer()
{
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_num);
}