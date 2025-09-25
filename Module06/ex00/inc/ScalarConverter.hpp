/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:45:03 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 15:00:48 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

enum LiteralType{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID
};

class	ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void	convert(std::string const &);
		static LiteralType	detectType(std::string const &);
};