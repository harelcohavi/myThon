#pragma once

#include "InterpreterException.h"
#include <iostream>

class NameErrorExcaption : public  InterpreterException
{
public:
	NameErrorExcaption(std::string name);

	const char* what() const override;
private:
	std::string _name;
};
