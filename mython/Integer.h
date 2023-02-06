#pragma once

#include <iostream>
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int value);
	~Integer();

	bool isPrintable() const override;
	std::string toString() const override;

private:
	int _num;
};

