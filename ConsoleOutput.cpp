#include "ConsoleOutput.h"
#include <string>
#include <utility>

ConsoleOutput::ConsoleOutput(ArithmeticСalculator ar, StringCheck sChek) : ar_(ar), sChek_(sChek)
{
	initialize();
}

ConsoleOutput::~ConsoleOutput()
{
	// восстанавливаем прежний вывод
	std::cout << std::resetiosflags(std::cout.flags());
}

void ConsoleOutput::show()
{
	std::string str{};
	std::pair<bool, std::string> stringCheck{};
	int menuItem = 0;
	
#ifndef __APPLE__
	system("cls");
#else
#ifndef __linux__
	system("cls");
#endif // !__linux__
#endif // __APPLE__
	
	std::cout << "\nВведите строку: ";
	std::getline(std::cin, str);

	stringCheck = sChek_.check(str);

	if (!stringCheck.first)	
		std::cout << "Ошибка " << stringCheck.second << std::endl;	
	else
		std::cout << str << '\t' << ar_.calculate(str) << std::endl;	


#ifndef __APPLE__
		system("pause");
#else
#ifndef __linux__
		system("pause");
#endif // !__linux__

#endif // __APPLE__			   	
}

void ConsoleOutput::initialize()
{
	// устанавливаем необходимые флаги вывода
	std::cout << std::setprecision(3) << std::fixed;
	std::cout << std::setw(18);
}
