/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:36 by volmer            #+#    #+#             */
/*   Updated: 2025/11/11 13:44:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        PmergeMe pm(argc, argv);
        pm.printBefore();
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}