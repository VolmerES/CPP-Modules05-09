/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:54:40 by volmer            #+#    #+#             */
/*   Updated: 2025/09/26 12:39:17 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/creator.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>

Base*	generate(void) {
	
	bool seed;

	seed = false;
	if (!seed) {
		std::srand(static_cast<unsigned>(std::time(0)));
		seed = true;
	}
	int rand = std::rand() % 3;
	switch (rand) {
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}

void	identify(Base* p) {
	
	if (p == NULL) {
		std::cout << "Unknown" << std::endl;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
 	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
	
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}
		try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}
		try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
	std::cout << "Unknown" << std::endl;
}