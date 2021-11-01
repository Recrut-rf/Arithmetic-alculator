#include "StringCheck.h"

std::pair<bool, std::string> StringCheck::check(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isValidCharacter(str[i]))
			return std::make_pair(false, "Некорректный символ в выражении!");

		if(i < (str.size() - 1))
			if(isOperation(str[i]) && isOperation(str[i + 1]))
				return std::make_pair(false, "В выражении арифметические операции идут подряд друг за другом!");
	}

	if(!isValidScope())
		return std::make_pair(false, "Скобки в выражении не симметричны!");

	return std::make_pair(true, "");
}

bool StringCheck::isValidCharacter(char ch)
{
	switch (ch)
	{
	case '(':
		++scope;
		return true;
	case '[':
		++scope;
		return true;
	case ')':
		--scope;
		return true;
	case ']':
		--scope;
		return true;
	case '/':
		return true;
	case '*':
		return true;
	case '-':
		return true;
	case '+':
		return true;
	case '.':
		return true;
	case '0':
		return true;
	case '1':
		return true;
	case '2':
		return true;
	case '3':
		return true;
	case '4':
		return true;
	case '5':
		return true;
	case '6':
		return true;
	case '7':
		return true;
	case '8':
		return true;
	case '9':
		return true;
	default:
		return false;
	}
}

bool StringCheck::isValidScope()
{	
	return scope ? false : true;
}

bool StringCheck::isOperation(char ch)
{
	switch (ch)
	{
	case '/':
		return true;
	case '*':
		return true;
	case '-':
		return true;
	case '+':
		return true;
	default:
		return false;
	}
}
