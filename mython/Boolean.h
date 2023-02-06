#pragma once

#include <iostream>
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool value);
	~Boolean();

	bool isPrintable() const override;
	std::string toString() const override;

private:
	bool _value;
};