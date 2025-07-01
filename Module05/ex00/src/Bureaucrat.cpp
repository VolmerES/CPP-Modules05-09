/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:03:53 by volmer            #+#    #+#             */
/*   Updated: 2025/07/01 19:43:38 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade) {
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
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &buro) {
	out << buro.getName() << ", bureaucrat grade " << buro.getGrade() << "." << std::endl;
}