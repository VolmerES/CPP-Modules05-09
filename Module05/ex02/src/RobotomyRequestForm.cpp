/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.CPP                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:44:38 by volmer            #+#    #+#             */
/*   Updated: 2025/09/18 11:14:59 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
:
	AForm(other),
	_target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    // 1) Verificar con checkExecutable(executor)
	checkExecutable(executor);
	
    // 2) Imprimir un mensaje de "taladrando ruidos..." (drilling noises)
	std::cout << "drilling noises..." << std::endl;

    // 3) Generar un número aleatorio (rand() % 2)
	if (rand() % 2 == 0){
		std::cout << "robotomization of " << this->_target << " has fail" << std::endl;
	}
	else
		std::cout << "robotomization of " << this->_target << " suceed" << std::endl;

    // 4) Si es 0 -> imprimir que la robotomización de <target> ha fallado
    //    Si es 1 -> imprimir que <target> ha sido robotomizado con éxito
}
