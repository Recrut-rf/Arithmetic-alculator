#pragma once

#include <string>
#include <stack> 
#include <map>
#include <sstream>


class ArithmeticСalculator
{
public:
	ArithmeticСalculator();

	// рассчёт арифметического выражения
	// проверок на правильность строки никаких нет
	// потому как если они и нужны, то для этого нужен отдельный метод,
	// а лучше класс (каждый должен заниматься своим делом)
	// поэтому примем за истину, что строка корректна
	double calculate(std::string inputStr);

private:
	
	// символ есть операция или что-то иное 	
	bool isOperation(char ch);
	 
	// символ есть число или что то иное
	bool isNumber(char ch);

	// проверка на закрывающие скобки
	bool isCloseScope(char ch);

	// проверка на открывающие скобки
	bool isOpenScope(char ch);

	// перевод строки в вещественное число
	double stringToDouble(std::string &str);

	// рассчёт арифметической операции 
	// и добавление результата в результирующий стек
	void calculation(char op);

	// веса операций
	std::map<char, size_t> transactionWeights_{}; 

	// коллекция операций	
	std::map<char, double(*)(double, double)> operations_
	{
		{'+', [](double a, double b) {return a + b;}},
		{'-', [](double a, double b) {return a - b;}},
		{'*', [](double a, double b) {return a * b;}},
		{'/', [](double a, double b) {return a / b;}}
	};
		
	std::string outputStr_{};

	std::stack<double> numbers_{};
	std::stack<char> op_{};	
	
	bool unaryMinus_{};
};

