/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:44:31 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 14:06:27 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv) {

	if (argc != 2){
		std::cout << "Invalid Format" << std::endl;
		std::cout << "Usage: ./convert \"value\"" << std::endl;
		return(1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}