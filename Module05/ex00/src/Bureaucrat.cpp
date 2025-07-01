/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:03:53 by volmer            #+#    #+#             */
/*   Updated: 2025/07/01 19:36:30 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade) {
	if (&name) {
		if (grade <= 0)
			throw Bureaucrat::GradeTooHighException();
		if (grade >=151)
			throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	_grade(other.getGrade());
	_name(other.getName());
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
			_grade(other.getGrade());
			_name(other.getName());
	}
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade >= 2)
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade <= 149)
		_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &buro) {
	out << buro.getName() << ", bureaucrat grade " << buro.getGrade() << "." << std::endl;
}