#include "String.h"

String::String(std::string string)
	: _str(string) ,Sequence()
{
}

String::~String()
{
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	bool haveDash = false;
	int i = 0;

	for (i = 0; i < this->_str.length() && !haveDash; i++)
	{
		if (this->_str[i] == '\'')
		{
			haveDash = true;
		}
	}

	if (haveDash)
	{
		return "\"" + this->_str + "\"";
	}
	else
	{
		return "\'" + this->_str + "\'";
	}
}