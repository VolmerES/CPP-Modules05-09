/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:12 by volmer            #+#    #+#             */
/*   Updated: 2025/11/06 13:14:48 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rpn.hpp"

int	RPN::evaluate(const std::string expr)
{	
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
	if (stack.size() > 1)
		throw std::runtime_error("Invalid expression");
	else if (stack.empty())
		throw std::runtime_error("Invalid expression");
	std::cout << stack.top() << std::endl;
	
}