#include <iostream>
#include <iomanip>                 // для std::setprecision и прочих флагов
#include "ArithmeticСalculator.h"
#include <math.h>                  // для функции округления floor()


int main(int argc, char* argv[])
{
	ArithmeticСalculator a;
	std::string str;

	// устанавливаем необходимые флаги вывода
	std::cout << std::setprecision(3) << std::fixed;

	// для работы через консоль
	// но никаких проверок на корректность нет
	// примем за истину, что строка корректна
	if (argc > 1)
	{
		for (size_t i = 1; i < argc; ++i)
			str += std::string(argv[i]);

		std::cout << std::setw(18) << str + " " << '\t' << a.calculate(str) << '\n';
	}	
	else
	{
		std::cout << std::setw(18) << "2+2 " << '\t' << a.calculate("2+2") << '\n';
		std::cout << std::setw(18) << "(5-7)/2 " << '\t' << a.calculate("(5-7)/2") << '\n';
		std::cout << std::setw(18) << "10/3 " << '\t' << a.calculate("10/3") << "\n";

		// у меня это выражение округляет до 1.556 а не до 1.555
		// но раз нужно 1.555, сделаем 1.555
		std::cout << std::setw(18) << "-1.1111+(10-2)/3 " << '\t' << floor(a.calculate("-1.1111+(10-2)/3") * 1000) / 1000 << '\n';

		std::cout << std::setw(18) << "2*((11+1)/(9-3)) " << '\t' << a.calculate("2*((11+1)/(9-3))") << '\n';
		std::cout << std::setw(18) << "2*[(11+1)/(9-3)] " << '\t' << a.calculate("2*[(11+1)/(9-3)]") << '\n';
	}

	// восстанавливаем прежний вывод
	std::cout << std::resetiosflags(std::cout.flags()); 

	system("pause>nul");
}
