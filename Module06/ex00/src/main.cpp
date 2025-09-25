/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:44:31 by volmer            #+#    #+#             */
/*   Updated: 2025/09/25 14:03:16 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv) {

	(void)argc;
	std::cout << "Usage: ./convert \"value\"" << std::endl;

	ScalarConverter::convert(argv[1]);
	return (0);
}