#pragma once
#include "InterpreterException.h"
#include <iostream>

class SyntexException : public InterpreterException
{
public:
	const char* what() const override;
private:

};