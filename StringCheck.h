#pragma once

#include <string>
#include <utility>


class StringCheck
{
public:

	StringCheck() = default;

	std::pair<bool, std::string> check(std::string str);

private:

	// проверка на корректный символ 	
	bool isValidCharacter(char ch);

	// проверка на корректность скобок
	bool isValidScope();

	bool isOperation(char ch);

	size_t scope{};
};

