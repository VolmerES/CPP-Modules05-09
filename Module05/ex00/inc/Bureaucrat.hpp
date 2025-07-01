/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:54:56 by volmer            #+#    #+#             */
/*   Updated: 2025/07/01 19:31:05 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat {
	private:
		int	_grade;
		const std::string  _name;
	public:
		Bureaucrat::Bureaucrat(const std::string& name, const int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		
		std::string	getName() const;
		int	getGrade() const;

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
		
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &buro);