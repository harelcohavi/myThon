#include "SyntaxException.h"

const char* SyntexException::what() const
{
	return "SyntaxError: invalid syntax";
}