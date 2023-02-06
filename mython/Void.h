#pragma once

#include <iostream>
#include "Type.h"

class Void : public Type
{
public:
	Void();
	~Void();

	bool isPrintable() const override; 
	std::string toString() const override;

private:
};

