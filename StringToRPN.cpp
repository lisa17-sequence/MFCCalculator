#include "pch.h"
#include "StringToRPN.h"


std::string StringToRPN::RPN(std::string str)
{
    for (int i = 0; i < str.size(); ++i) // учёт отрицательных чисел
    {
        if ((str[i] == '+' || str[i] == '-') && (0 == i || (!isalnum(str[i - 1]) && str[i - 1] != '.' && str[i - 1] != ')')))
        {
            auto it = std::find_if(str.begin() + i + 1, str.end(), [](char const c) {return !isalnum(c); });
            str.insert(it, ')');
            str.insert(i, "(0");
        }
    }
    std::map<char, size_t> map; // карта весов символов
    map.insert({ '^', 4 });
    map.insert({ '*', 3 });
    map.insert({ '/', 3 });
    map.insert({ '+', 2 });
    map.insert({ '-', 2 });
    map.insert({ '(', 1 });
    std::string srpn;
    std::stack<char> stack;
    for (auto c : str) // формировка результирующей строки в ОПЗ (rpn)
    {
        if (!isalnum(c) && ('.' != c))
        {
            srpn += ' ';
            if (')' == c)
            {
                while (stack.top() != '(')
                {
                    srpn += stack.top();
                    stack.pop();
                    srpn += ' ';
                }
                stack.pop();
            }
            else if ('(' == c)
            {
                stack.push(c);
            }
            else if (stack.empty() || (map[stack.top()] < map[c]))
            {
                stack.push(c);
            }
            else
            {
                do
                {
                    srpn += stack.top();
                    srpn += ' ';
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()] < map[c])));
                stack.push(c);
            }
        }
        else
        {
            srpn += c;
        }
    }
    while (!stack.empty())// остаток из стека добавляется в результирующую строку
    {
        srpn += ' ';
        srpn += stack.top();
        srpn += ' ';
        stack.pop();
    }
    return srpn;
}