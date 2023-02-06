#pragma once

#include "Sequence.h"
#include <iostream>

class String : public Sequence
{
public:
	String(std::string string);
	~String();

	bool isPrintable() const override;
	std::string toString() const override;

private:
	std::string _str;
};

