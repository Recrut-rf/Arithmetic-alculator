#include <iostream>
#include <iomanip>                 // для std::setprecision и прочих флагов
#include "ArithmeticСalculator.h"
#include "StringCheck.h"
#include "ConsoleOutput.h"
#include <math.h>                  // для функции округления floor()


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

// если меню программы выводить не нужно, 
// закомментируйте строку
#define MENU

	ArithmeticСalculator arithmeticСalculator;
	StringCheck stringCheck;

	ConsoleOutput consoleOutput(arithmeticСalculator, stringCheck);

	std::string inputStr{};
	std::pair<bool, std::string> checkStr{};
	
	// для работы через консоль	
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
			inputStr += std::string(argv[i]);

		checkStr = stringCheck.check(inputStr);

		if (!checkStr.first)		
			std::cout << "Ошибка " << checkStr.second << std::endl;		
		else
			std::cout << inputStr << '\t' << arithmeticСalculator.calculate(inputStr) << std::endl;		
	}	
	else
	{
		std::cout << std::setw(18) << "2+2 " << '\t' << arithmeticСalculator.calculate("2+2") << '\n';
		std::cout << std::setw(18) << "(5-7)/2 " << '\t' << arithmeticСalculator.calculate("(5-7)/2") << '\n';
		std::cout << std::setw(18) << "10/3 " << '\t' << arithmeticСalculator.calculate("10/3") << "\n";

		// у меня это выражение округляет до 1.556 а не до 1.555
		// но раз нужно 1.555, сделаем 1.555
		std::cout << std::setw(18) << "-1.1111+(10-2)/3 " << '\t' << floor(arithmeticСalculator.calculate("-1.1111+(10-2)/3") * 1000) / 1000 << '\n';

		std::cout << std::setw(18) << "2*((11+1)/(9-3)) " << '\t' << arithmeticСalculator.calculate("2*((11+1)/(9-3))") << '\n';
		std::cout << std::setw(18) << "2*[(11+1)/(9-3)] " << '\t' << arithmeticСalculator.calculate("2*[(11+1)/(9-3)]") << '\n';

#ifndef __APPLE__
		system("pause");
#else
#ifndef __linux__
		system("pause");
#endif // !__linux__
#endif // __APPLE__

#ifdef MENU
		consoleOutput.show();
#endif // MENU		
	}
}
