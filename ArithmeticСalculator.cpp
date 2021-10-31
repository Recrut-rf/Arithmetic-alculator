#include "ArithmeticСalculator.h"

ArithmeticСalculator::ArithmeticСalculator()
{
	transactionWeights_.insert(std::make_pair('*', 3));
	transactionWeights_.insert(std::make_pair('/', 3));
	transactionWeights_.insert(std::make_pair('+', 2));
	transactionWeights_.insert(std::make_pair('-', 2));
	transactionWeights_.insert(std::make_pair('(', 1));
}

double ArithmeticСalculator::calculate(std::string inputStr)
{
	for (size_t i{}; i < inputStr.size(); ++i)
	{
		// если символ цифра
		if (isNumber(inputStr[i]))
		{
			// добавляем его в выходную строку
			outputStr_.push_back(inputStr[i]);
			
			// если символ последний во входной строке
			if (i == (inputStr.size() - 1))
			{
				// проверяем, что это не закрывающая скобка 
				if(!isCloseScope(inputStr[i]))
					if (outputStr_ != "") // проверка на случай, если строка, из которой берём число, пустая
						                  // такое может быть например при вот таком выражении ((5-7))/2						                 
						numbers_.push(stringToDouble(outputStr_));  

				// если в стеке уже есть операция
				// и она с большим или равным приоритетом 
				if (op_.size() > 0 && ((transactionWeights_[op_.top()] > transactionWeights_[inputStr[i]])
					|| (transactionWeights_[op_.top()] == transactionWeights_[inputStr[i]])))
				{
					// проверка на наличие чисел в стеке
					if (numbers_.size() > 0) 
						calculation(op_.top());					
					
					while (op_.size() > 0)  // возможно цикл здесь лишний
					{						
						if (isOpenScope(op_.top()))
							break;

						// проверка на наличие чисел в стеке
						if (numbers_.size() > 0) 
							calculation(op_.top());						
					}					
				}
			}
			continue;
		}
		// числа находятся между операторами, 
		// предположим, что оператор не может быть последним в строке
		// а значит если i == (inputStr.size() - 1) то это последнее число выражения
		if (isOperation(inputStr[i]) && (i > 0))
		{
			// если в стеке уже есть операция
			// и она с большим приоритетом либо равным приоритетом
			if (op_.size() > 0 && ((transactionWeights_[op_.top()] > transactionWeights_[inputStr[i]])
				|| (transactionWeights_[op_.top()] == transactionWeights_[inputStr[i]])))
			{
				if (outputStr_ != "") // проверка на случай, если строка, из которой берём число, пустая
									  // такое может быть например при вот таком выражении ((5-7))/2
					numbers_.push(stringToDouble(outputStr_));

				if (numbers_.size() > 0) // проверка на наличие чисел в стеке
					calculation(op_.top());	
				
				
				op_.push(inputStr[i]);
				continue;
			}
			else
			{
				// если самым первым символом строки был унарный- 			
				if (unaryMinus_)
				{
					if (outputStr_ != "")
						// просто кладём значение в стек с числами со знаком -
						numbers_.push(-(stringToDouble(outputStr_)));

					// добавляем операцию в стек
					op_.push(inputStr[i]);
					unaryMinus_ = false;
					continue;
				}

				// если нет, то это операция и просто кладём её в стек 
				op_.push(inputStr[i]);
				// и добавляем число в стек с числами
				if (outputStr_ != "")
					numbers_.push(stringToDouble(outputStr_));				
			}			
		}
		if (isOpenScope(inputStr[i]))
		{
			op_.push(inputStr[i]);
			continue;
		}

		if (isCloseScope(inputStr[i]))
		{
			if (outputStr_ != "") // проверка на случай, если строка, из которой берём число, пустая
								  // такое может быть например при вот таком выражении ((5-7))/2
				numbers_.push(stringToDouble(outputStr_));

			if (numbers_.size() > 0) // проверка на наличие чисел в стеке
				calculation(op_.top());

			// если операций в стеке операций больше 1
			if (op_.size() > 1)
				// удаляем открывающую скобку из стека операций
			    op_.pop();
			continue;
		}

		// предположим, что выражений вида +число, не будет использовано
		// а выражения вида -число вполне может быть
		if ((i == 0) && (inputStr[i] == '-'))
			unaryMinus_ = true;
	}

	// если разобрали всю строку, но в стеке операций остались операции и они не открывающие скобки
	if (op_.size() > 0 && !isOpenScope(op_.top()))
		// то нужно произвести расчёты
		calculation(op_.top());

	return numbers_.top();
}

bool ArithmeticСalculator::isOperation(char ch)
{
	switch (ch)
	{
	case '/':
	case '*':
	case '-':
	case '+':
		return true;
	default:
		return false;
	}
}

bool ArithmeticСalculator::isNumber(char ch)
{
	switch (ch)
	{
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

bool ArithmeticСalculator::isCloseScope(char ch)
{
	if (ch == ')' || ch == ']')
		return true;
	else
		return false;
}

bool ArithmeticСalculator::isOpenScope(char ch)
{
	if (ch == '(' || ch == '[')
		return true;
	else
		return false;
}

double ArithmeticСalculator::stringToDouble(std::string &str)
{
	double temp;
	std::istringstream(str) >> temp;
	str.clear();
	return temp;
}

void ArithmeticСalculator::calculation(char op)
{	
	if (isOpenScope(op))
		return;
	
	auto pop_stack([&]() { auto r(numbers_.top()); numbers_.pop(); return r; });

	const auto r{ pop_stack() };
	const auto l{ pop_stack() };

	// результирующий стек
	numbers_.push(operations_.at(op)(l, r));
	// удаляем операцию из стека
	op_.pop();
}
