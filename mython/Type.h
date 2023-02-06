#pragma once

#include <iostream>

class  Type
{
public:
	 Type();
	~ Type();

	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

	void setTemp(bool temp);
	bool isTemp();

private:
	bool _isTemp;
};


