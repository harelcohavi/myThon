#include "Type.h"

Type::Type()
	:_isTemp(false)
{
}

Type::~Type()
{
}

void Type::setTemp(bool temp)
{
	this->_isTemp = temp;
}

bool Type::isTemp()
{
	return this->_isTemp;	
}