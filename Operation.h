#pragma once

#include <functional>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <stack>


class Operation
{
private:
    std::string expression;
    std::string result;
public:
    std::string answer_to_expression(std::string str); //выражение (опз)(rpn) преобразовывается в конечный ответ
    void performOp(const char input, std::stack<double>& container);
    Operation(std::string expression_) {
        expression = expression_;
        result = answer_to_expression(expression_);
        std::cout << result << '\n';

    }
    std::string getResult() {
        return result;
    }
};

