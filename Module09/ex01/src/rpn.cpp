/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:12 by volmer            #+#    #+#             */
/*   Updated: 2025/11/10 16:28:26 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rpn.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other) : stack(other.stack) {}
RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return (*this);
}
RPN::~RPN(){}

int RPN::applyOperator(char op, int a, int b)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return (a / b);
	}
	else
		throw std::runtime_error("Invalid operator");
}

bool	RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::evaluate(const std::string expr)
{	
	if (expr.empty())
		throw std::runtime_error("Invalid expression");
	while (!stack.empty())
		stack.pop();
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr[i] == ' ')
			continue;
		else if (expr[i] >= '0' && expr[i] <= '9')
			stack.push(expr[i] - '0');
		else if (isOperator(expr[i]))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			stack.push(applyOperator(expr[i], a, b));
		}
		else
			throw std::runtime_error("Invalid token");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return (stack.top());
}