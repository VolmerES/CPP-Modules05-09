/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:45:01 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 14:52:11 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	ft_is_imposible(void){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
	return;
}

LiteralType	ScalarConverter::detectType(std::string const & literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		return (PSEUDO_FLOAT);
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		return (PSEUDO_DOUBLE);
	}
	else if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (CHAR);
	else if (!literal.empty() && (literal[0] == '+' || literal[0] == '-' 
			|| isdigit(static_cast<unsigned char>(literal[0])))) {
   		bool   isInt = true;
    	size_t i = 0;
		
    	if (literal[0] == '+' || literal[0] == '-') {
    	    i = 1;
    	    if (i >= literal.length()) {
    	        isInt = false;
    	    }
    	}
	
    	while (isInt && i < literal.length()) {
    	    if (!isdigit(static_cast<unsigned char>(literal[i]))) {
    	        isInt = false;
    	        break;
    	    }
    	    i++;	
    	}
	
    	if (isInt) {
    	    return (INT);
    	}
		else
			return (INVALID);
	}
	else if (literal.length() > 2 && (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))) {
		bool hasDot = false;
		bool isFloat = true;
		for (size_t i = 0; i < literal.length() - 1; ++i) {
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
		if (isFloat && hasDot && literal[literal.length()-1] == 'f')
			return FLOAT;
	}
	else if (literal.length() > 1 && (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))) {
		bool hasDot = false;
		bool isDouble = true;
		for (size_t i = 1; i < literal.length(); ++i) {
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
	LiteralType Type = detectType(literal);
	if (literal.empty() || Type == INVALID) {
		ft_is_imposible();
		return;
	}
	char	c;
	int		i;
	float	f;
	double	d;
	bool	impossible = false;
	
	if (Type == CHAR) {
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		std::cout << "char: " << c << std::endl;
    	std::cout << "int: " << i << std::endl;
    	std::cout << "float: " << f << ".0f" << std::endl;
       	std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (Type == INT) {
		long typeInt = std::strtol(literal.c_str(), NULL, 10);
		if (typeInt > INT_MAX || typeInt < INT_MIN){
			impossible = true;;
		}
		if (!impossible) {
			i = static_cast<int>(typeInt);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			if (i < 0 || i > 127)
				std::cout << "char: impossible" << std::endl;
			else if	(!isprint(c))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << c << std::endl;
        	std::cout << "int: " << i << std::endl;
        	std::cout << "float: " << f << ".0f" << std::endl;
        	std::cout << "double: " << d << ".0" << std::endl;
			return;
		}
		else if (impossible)
			std::cout << "Non displayable" << std::endl;
			return;
	}
	else if (Type == FLOAT)
	{
		f = std::strtof(literal.c_str(), NULL);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		std::cout << "char: " << c << std::endl;
    	std::cout << "int: " << i << std::endl;
    	std::cout << "float: " << f << ".0f" << std::endl;
       	std::cout << "double: " << d << ".0" << std::endl;
		return;
	}
	else if (Type == DOUBLE)
	{
		d = std::strtod(literal.c_str(), NULL);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		std::cout << "char: " << c << std::endl;
    	std::cout << "int: " << i << std::endl;
    	std::cout << "float: " << f << ".0f" << std::endl;
       	std::cout << "double: " << d << ".0" << std::endl;
		
		return;
	}
	else if (Type == PSEUDO_DOUBLE || Type == PSEUDO_FLOAT) {
		if (literal == "nan") {
    		std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
    		std::cout << "float: nanf" << std::endl;
    		std::cout << "double: nan" << std::endl;
			return;
		}
		else if (literal == "+inf") {
    		std::cout << "char: impossible" << std::endl;
    		std::cout << "int: impossible" << std::endl;
    		std::cout << "float: +inff" << std::endl;
    		std::cout << "double: +inf" << std::endl;
			return;
		}
		else if (literal == "-inf") {
    		std::cout << "char: impossible" << std::endl;
    		std::cout << "int: impossible" << std::endl;
    		std::cout << "float: -inff" << std::endl;;
    		std::cout << "double: -inf" << std::endl;
			return;
		}
	}
}