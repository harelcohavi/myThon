#include "Boolean.h"

Boolean::Boolean(bool value)
	: _value(value) ,Type()
{
}

Boolean::~Boolean()
{
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	return this->_value ? "True" : "False";
}