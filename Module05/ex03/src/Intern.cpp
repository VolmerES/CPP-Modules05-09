/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:11:37 by volmer            #+#    #+#             */
/*   Updated: 2025/09/18 13:11:31 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <string>

Intern::Intern() {}
Intern::Intern(const Intern & other) { (void)other; }
Intern& Intern::operator=(const Intern & other) {  (void)other; return *this; }
Intern::~Intern() {}

AForm*	Intern::createShrubbery(const std::string & target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string & target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string & target) {
	return new PresidentialPardonForm(target);	
}

AForm*	Intern::makeForm(const std::string & formName, const std::string & target) const {
	std::string formNames[] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	formFunction functionCreator[] = {
		&Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
	};

	int size = sizeof(formNames) / sizeof(formNames[0]);

	for (int i = 0; i < size; i++) {
		if (formName == formNames[i]) {
			AForm* form = functionCreator[i](target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}

	std::cout << "Intern: unknown form name " << formName << std::endl;
	return NULL;
	
}