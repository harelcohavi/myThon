#include "Parser.h"
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Void.h"
#include <iostream>
#include <string>

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str)
{
	Type* value = nullptr;

	if (str.length() > 0)
	{
		if (str[0] == ' ' || str[0] == '\t')
		{
			throw IndentationException();
		}

		value = getVariableValue(str);
		if (value != nullptr)
		{
			return value;
		}
		if (makeAssignment(str))
		{
			return new Void();
		}

		Helper::rtrim(str);

		value = getType(str);
		if (value == nullptr)
		{
			delete value;
			throw SyntexException();
		}
		return value;
		
	}

	return nullptr;
}

Type* Parser::getType(std::string str)
{
	bool number = false;

	if (str == "True" || str == "False")
	{
		bool boolean = (str == "True") ? true : false;
		 return new Boolean(boolean);
	}

	if (str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9'))
	{
		number = true;

		for (int i = 1; i < str.length() && number; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				number = false;
			}
		}
	}

	if (number)
	{
		return new Integer(std::stoi(str));
	}

	if ((str[0] == '\'' || str[0] == '\"') && str[str.length() - 1/*last char*/] == str[0])
	{
		int start = 1;
		int end = str.length() - 2;

		return new String(str.substr(start, end - start + 1));
	}

	return nullptr;
}

bool Parser::isLegalVarName(std::string str)
{
	bool legal = true;
	int i = 0;

	for (i = 0; i < str.length() && legal; i++)
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && str[i] != '_')
		{
			legal = false;
		}
	}

	return legal;
}

bool Parser::makeAssignment(std::string str)
{
	int numOfEqual = 0;
	int i = 0;
	std::string varingName = " ";
	std::string value = " ";
	int equalIndex = 0;
	Type* varing = nullptr;

	for (i = 0; i < str.length() && numOfEqual < 2; i++)
	{
		if (str[i] == '=')
		{
			numOfEqual++;
			if (numOfEqual == 1)
			{
				equalIndex = i;
			}
		}
	}

	if (numOfEqual != 1)
	{
		return false;
	}

	varingName = str.substr(0, equalIndex);//same as str[0 - equalIndex] in python
	value = str.substr(equalIndex + 1, str.length() - equalIndex + 1);

	Helper::trim(varingName);
	Helper::trim(value);

	if (!isLegalVarName(varingName))
	{
		throw NameErrorExcaption(varingName);
	}

	varing = Parser::getType(value);

	if (varing == nullptr)
	{
		delete varing;
		if (isLegalVarName(value))
		{
			Type* secondVaring = Parser::getVariableValue(value);
			if (secondVaring != nullptr)
			{
				_variables[varingName] = getType(secondVaring->toString());
				_variables[varingName]->setTemp(secondVaring->isTemp());
			}

			return true;
		}
		else
		{
			throw SyntexException();
		}
	}
	varing->setTemp(false);
	_variables[varingName] = varing;
	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	if (_variables.find(str) != _variables.end())
	{
		return _variables[str];
	}
	else
	{
		return nullptr;
	}
}

void Parser::clearVaring()
{
	for (auto it = _variables.begin(); it != _variables.end(); it++)
	{
		delete it->second;
	}
}
