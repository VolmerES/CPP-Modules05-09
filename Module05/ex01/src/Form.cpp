/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:51:44 by jdelorme          #+#    #+#             */
/*   Updated: 2025/08/26 13:09:53 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if ( _gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
: 	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::string const&	Form::getName() const {
	return (this->_name);
}

bool				Form::isSigned() const {
	return (this->_isSigned);
}

int					Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int					Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high");
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
	os << "Form: " << form.getName() << " Signed: " << form.isSigned() << " Sign grade: " << form.getGradeToSign() << " Exec grade: " << form.getGradeToExecute();
	return (os);
}

void		Form::beSigned(Bureaucrat const& Buro) {
	if (Buro.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

Form::~Form() {}