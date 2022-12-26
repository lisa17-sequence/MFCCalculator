#include "pch.h"
#include "Operation.h"
#include <cmath>
std::string Operation::answer_to_expression(std::string s)
{
	std::map<char, std::function<int(const int64_t&, const int64_t&)>> operations;
	operations['+'] = [](const int64_t& a, const int64_t& b) { return a + b; };
	operations['-'] = [](const int64_t& a, const int64_t& b) { return a - b; };
	operations['*'] = [](const int64_t& a, const int64_t& b) { return a * b; };
	operations['/'] = [](const int64_t& a, const int64_t& b) { return a / b; };

	const auto isOperation = [](const char operation)
	{
		const char ops[] = { '-', '+', '*', '/', '^' };
		for (std::size_t i = 0; i < sizeof(ops) / sizeof(char); ++i)
		{
			if (operation == ops[i])
			{
				return true;
			}
		}
		return false;
	};

	std::stack<double> stack_;

	std::string subNumber{};
	for (std::size_t index = 0; index < s.size(); ++index)
	{
		if (s[index] == ' ' && !subNumber.empty())
		{
			stack_.push(std::stod(subNumber.c_str()));
			subNumber.clear();
		}
		else if (isOperation(s[index]))
		{
			performOp(s[index], stack_);
		}
		if (s[index] != ' ' && !isOperation(s[index]))
		{
			subNumber.push_back(s[index]);
		}
	}

	return std::to_string(stack_.top());
}

void Operation::performOp(const char input, std::stack<double>& container)
{
	std::map<char, std::function<double(const double, const double)>> operations;
	operations['+'] = [](const double a, const double b) { return (a + b); };
	operations['-'] = [](const double a, const double b) { return (a - b); };
	operations['*'] = [](const double a, const double b) { return (a * b); };
	operations['/'] = [](const double a, const double b) { return (a / b); };
	operations['^'] = [](const double a, const double b) { return (pow(a, b)); };


	double rvalue = container.top();
	container.pop();
	double lvalue = container.top();
	container.pop();

	double result = operations[input](lvalue, rvalue);
	container.push(result);
}
