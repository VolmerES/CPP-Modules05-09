/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:24:42 by volmer            #+#    #+#             */
/*   Updated: 2025/11/06 13:10:33 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>


class	RPN {
	private:
		std::stack<int> stack;
		bool	isOperator(char c);
		int		applyOperator(char op, int a, int b);
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	evaluate(const std::string expr);
};