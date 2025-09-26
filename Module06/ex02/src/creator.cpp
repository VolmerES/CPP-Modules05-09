/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:54:40 by volmer            #+#    #+#             */
/*   Updated: 2025/09/26 12:13:55 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/creator.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

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