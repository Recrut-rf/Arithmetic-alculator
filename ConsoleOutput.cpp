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

	std::cout << "\n1. Ввод выражения: " << std::endl;
	std::cout << "2. Повторить? " << std::endl;
	std::cout << "3. Выход " << std::endl;
	std::cout << "Выберете пункт меню: ";		

	std::cin >> menuItem;

	switch (menuItem)
	{
	case 1:
	case 2:
		std::cout << "Введите строку: ";
		std::cin >> str;
		stringCheck = sChek_.check(str);


		if (!stringCheck.first)
		{
			std::cout << "Ошибка " << stringCheck.second << std::endl;
			break;
		}
		else
			std::cout << str << '\t' << ar_.calculate(str) << std::endl;
	case 3:
		std::cout << "Благодарим за работу." << std::endl;
		break;	
	default:
		std::cout << "Такого пункта в меню нет. Программа завершается " << std::endl;
	}
		

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
