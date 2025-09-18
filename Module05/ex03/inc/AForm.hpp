/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:39:46 by jdelorme          #+#    #+#             */
/*   Updated: 2025/09/17 18:27:12 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <string>
class Bureaucrat;

class AForm {
	protected:
		void checkExecutable(Bureaucrat const & executor);
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int 			_gradeToExecute;
	public:
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		std::string	const&	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const& Buro);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNoSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void	checkExecutable(Bureaucrat const & executor) const;

		virtual void execute(Bureaucrat const & executor) const = 0;
		
};

std::ostream& operator<<(std::ostream& os, AForm const& form);