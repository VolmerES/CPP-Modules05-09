/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:25:35 by volmer            #+#    #+#             */
/*   Updated: 2025/09/18 11:13:41 by volmer           ###   ########.fr       */
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
    // 1) Verificar que el formulario está firmado y que el executor tiene el rango suficiente
    //    (usa checkExecutable(executor))
	checkExecutable(executor);

    // 2) Construir el nombre del archivo: "<target>_shrubbery"
	std::string name = _target + "_shrubbery";

    // 3) Abrir un ofstream con ese nombre
	std::ofstream target(name);

    // 4) Comprobar que el archivo se ha abierto correctamente
    //    -> si no, lanzar una excepción (std::runtime_error por ejemplo)
	if (!target.is_open()) {
		throw std::runtime_error("No se pudo abrir el archivo");
	}
	
    // 5) Escribir un par de árboles ASCII en el archivo
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

    // 6) Cerrar el archivo
	target.close();
}
