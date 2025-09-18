/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:03:53 by volmer            #+#    #+#             */
/*   Updated: 2025/09/16 17:39:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _grade(grade), _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _grade(other._grade), _name(other._name) {}


Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
			_grade = other.getGrade();
	}
	return *this;
}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &buro) {
	out << buro.getName() << ", bureaucrat grade " << buro.getGrade() << "." << std::endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

void		Bureaucrat::signForm(AForm &form) {
		try {
			form.beSigned(*this);
			std::cout << getName() << " signed " << form.getName() << std::endl;
		}
		catch (const AForm::GradeTooLowException& e)
		{
			std::cout << getName() << " couldn't sign " << form.getName() << " because "  << e.what() << std::endl;
		}
}