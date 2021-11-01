#pragma once

#include <iostream>
#include <iomanip>                 // ��� std::setprecision � ������ ������
#include "Arithmetic�alculator.h"
#include "StringCheck.h"


class ConsoleOutput
{
public:

	ConsoleOutput(Arithmetic�alculator ar, StringCheck sChek);
	~ConsoleOutput();

	void show();

private:

	void initialize();

	Arithmetic�alculator ar_;
	StringCheck sChek_;
};

