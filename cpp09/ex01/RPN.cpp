#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other) 
    {
        _stack = other._stack;
    }
    return *this;
}

bool RPN::isOperator(const std::string & token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::performOperation(const std::string & op, double operand1, double operand2)
{
    char c = op[0];

    if (c == '+')
        return operand1 + operand2;
    else if (c == '-')
        return operand1 - operand2;
    else if (c == '*')
        return operand1 * operand2;
    else if (c == '/')
    {
        if (operand2 == 0)
            throw std::runtime_error("Error");
        return operand1 / operand2;
    }
    throw std::runtime_error("Error");
}

void RPN::validateExpression(const std::string & expression)
{
    if (expression.empty())
        throw std::runtime_error("Error");

    for (size_t i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (!isdigit(c) && c != ' ' && c != '+' && c != '-' && c != '*' && c != '/')
            throw std::runtime_error("Error");
    }

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1)
        {
            char c = token[0];
            if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')
                continue;
        }
        throw std::runtime_error("Error");
    }
}

double RPN::evaluate(const std::string & expression)
{
    while (!_stack.empty())
        _stack.pop();

    validateExpression(expression);

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) && token.length() == 1)
        {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            double operand2 = _stack.top();
            _stack.pop();
            double operand1 = _stack.top();
            _stack.pop();

            double result = performOperation(token, operand1, operand2);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
