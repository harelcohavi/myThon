#pragma once

#include "Type.h"

class Sequence : public Type
{
public:
	Sequence();
	~Sequence();

	bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

private:
	
};