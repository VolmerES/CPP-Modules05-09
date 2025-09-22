/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:45:01 by volmer            #+#    #+#             */
/*   Updated: 2025/09/22 17:20:36 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

LiteralType	ScalarConverter::detectType(std::string const & literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		return (PSEUDO_FLOAT);
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		return (PSEUDO_DOUBLE);
	}
	else if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (CHAR);
	else if (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0])){
		bool isInt = true;
		for (int i = 1; i != literal.length(); i++) {
			if (!isdigit(literal[i])) {
				isInt = false;
				break;
			}
		}
		if (isInt)
			return (INT);
	}
	else if (literal.length() > 2 && (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))) {
		bool hasDot = false;
		bool isFloat = true;
		for (int i; i < literal.length() - 1; ++i) {
			if (literal[i] == '.') {
				if (hasDot) { 
					isFloat = false; break; 
				}
				hasDot = true;
			}
			else if (!isdigit(literal[i])) {
				isFloat = false;
				break;
			}
		}
		if (isFloat && hasDot && literal.back() == 'f')
			return FLOAT;
	}
	else if (literal.length() > 1 && (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))) {
		bool hasDot = false;
		bool isDouble = true;
		for (int i = 1; i < literal.length(); ++i) {
			if (literal[i] == '.') {
				if (hasDot) { 
					isDouble = false; break; 
				}
				hasDot = true;
			}
			else if (!isdigit(literal[i])) {
				isDouble = false;
				break;
			}
		}
		if (isDouble && hasDot && literal.back() != 'f')
			return DOUBLE;
	}
	return (INVALID);
}

void ScalarConverter::convert(std::string const & literal) {
	if (literal.empty()) {
		std::cerr << "Impossible" << std::endl;
	}
	LiteralType Type = detectType(literal);
	char	c;
	int		i;
	float	f;
	double	d;
	
	if (Type == CHAR) {
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	if (Type == INT) {
		
	}
}