/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:39:46 by jdelorme          #+#    #+#             */
/*   Updated: 2025/08/26 10:49:11 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int 			gradeToExecute;
	public:
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
};