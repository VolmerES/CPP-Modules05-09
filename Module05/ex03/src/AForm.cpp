/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:51:44 by jdelorme          #+#    #+#             */
/*   Updated: 2025/09/27 12:20:49 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) :
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

AForm::AForm(const AForm &other)
: 	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::string const&	AForm::getName() const {
	return (this->_name);
}

bool				AForm::isSigned() const {
	return (this->_isSigned);
}

int					AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int					AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Form grade too high");
}

const char* AForm::FormNoSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, AForm const& form) {
    os << "Form: " << form.getName()
       << " | Signed: ";
    if (form.isSigned())
        os << "yes";
    else
        os << "no";
    os << " | Sign grade: " << form.getGradeToSign()
       << " | Exec grade: " << form.getGradeToExecute();
    return os;
}

void		AForm::beSigned(Bureaucrat const& Buro) {
	if (Buro.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void		AForm::checkExecutable(Bureaucrat const & executor) const {
	if (!this->_isSigned)
		throw FormNoSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
}

AForm::~AForm() {}
