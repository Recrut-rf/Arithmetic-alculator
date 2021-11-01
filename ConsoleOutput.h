#pragma once

#include <iostream>
#include <iomanip>                 // äëÿ std::setprecision è ïğî÷èõ ôëàãîâ
#include "ArithmeticÑalculator.h"
#include "StringCheck.h"


class ConsoleOutput
{
public:

	ConsoleOutput(ArithmeticÑalculator ar, StringCheck sChek);
	~ConsoleOutput();

	void show();

private:

	void initialize();

	ArithmeticÑalculator ar_;
	StringCheck sChek_;
};

