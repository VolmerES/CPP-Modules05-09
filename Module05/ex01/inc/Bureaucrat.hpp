/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:54:56 by volmer            #+#    #+#             */
/*   Updated: 2025/08/26 13:20:25 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

class Form;

class Bureaucrat {
	private:
		int	_grade;
		const std::string  _name;
	public:
		Bureaucrat(const std::string& name, const int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		
		const std::string&	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void signForm(Form &form);
		
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &buro);