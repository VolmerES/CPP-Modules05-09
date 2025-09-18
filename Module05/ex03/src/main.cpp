/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:37:38 by volmer            #+#    #+#             */
/*   Updated: 2025/09/18 11:29:24 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
	std::cout << "\033[1;36m-------- CASO 1: Juan con grado 0 ---> FALLA --------\033[0m" << std::endl;
	try {
		Bureaucrat a("Juan", 0);
		std::cout << a << std::endl;
	}
	catch (std::exception &errora) {
		std::cerr << "\033[1;31m[ERROR] " << errora.what() << "\033[0m" << std::endl; 
	}

	std::cout << "\n\033[1;32m-------- CASO 2: Juan con grado 1 ---> FUNCIONA ------------------\033[0m" << std::endl;
	try {
		Bureaucrat b("Juan", 1);
		std::cout << b << std::endl;
	}
	catch (std::exception &errorb) {
		std::cerr << "\033[1;31m[ERROR] " << errorb.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[1;33m-------- CASO 3: Juan con grado 1, incrementamos ---> FALLA --------\033[0m" << std::endl;
	try {
		Bureaucrat b("Juan", 1);
		b.incrementGrade(); 
		std::cout << b << std::endl;
	}
	catch (std::exception &errorb) {
		std::cerr << "\033[1;31m[ERROR] " << errorb.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[1;36m-------- CASO 4: Juan con grado 151 ---> FALLA -------------------\033[0m" << std::endl;
	try {
		Bureaucrat c("Juan", 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &errorc) {
		std::cerr << "\033[1;31m[ERROR] " << errorc.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[1;36m-------- CASO 5: Juan con grado 100 intenta firmar 50 ---> FALLA -------------------\033[0m" << std::endl;
	Bureaucrat d("Juan", 100);
	ShrubberyCreationForm Form1("Hacienda");
	d.signForm(Form1);
	std::cout << Form1 << std::endl;

	std::cout << "\n\033[1;36m-------- CASO 6: Juan con grado 100 intenta firmar 150 ---> FUNCIONA -------------------\033[0m" << std::endl;
	Bureaucrat e("Juan", 100);
	RobotomyRequestForm Robot("Terminator");
	e.signForm(Robot);
	std::cout << Robot << std::endl;

	std::cout << "\n\033[1;36m-------- CASO 7: Juan intenta firmar un from ya firmado ---> FALLA -------------------\033[0m" << std::endl;
	try {
	Bureaucrat f("Juan ", 1);
	PresidentialPardonForm Perdon("Pardonez-moi");
	f.signForm(Perdon);
	Perdon.execute(f);
	std::cout << Perdon << std::endl;
	}
	catch (std::exception &error) {
    std::cerr << "\033[1;31m[ERROR] " << error.what() << "\033[0m" << std::endl;
}
	return 0;
}

