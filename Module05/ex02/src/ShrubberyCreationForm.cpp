/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:25:35 by volmer            #+#    #+#             */
/*   Updated: 2025/09/27 12:21:39 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
:	AForm("ShrubberyCreationForm", 145, 137),
 	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:	AForm(other),
	_target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

	checkExecutable(executor);

	std::string name = _target + "_shrubbery";

	std::ofstream target(name);
	if (!target.is_open()) {
		throw std::runtime_error("No se pudo abrir el archivo");
	}
	
	target <<
	"         ,%%%,%%%%%%%\n"
	"       ,'%% \\-*%%%%%%%\n"
	"     ;%%%%%*%   _%%%%\"\n"
	"      ,%%%       \\(_.*%%%%.\n"
	"      % *%%, ,%%%%*(    '\n"
	"    %^     ,*%%% )\\|,%%*%,_\n"
	"         *%    \\/ #).-\"*%%*\n"
	"             _.) ,/ *%,\n"
	"     _________/)#(_____________\n";

	target.close();
}
