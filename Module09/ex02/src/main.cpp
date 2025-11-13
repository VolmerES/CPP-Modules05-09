/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:52:36 by volmer            #+#    #+#             */
/*   Updated: 2025/11/13 13:04:10 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sys/time.h>

long	getMicroTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}


int main(int argc, char **argv)
{
    try {
        PmergeMe sorter(argc, argv);

        sorter.printBefore();

        long startV = getMicroTime();
        sorter.sortAll();    // vector
        long endV = getMicroTime();

        sorter.printAfter();

        long startD = getMicroTime();
        sorter.sortAllDeque();   // deque
        long endD = getMicroTime();

        std::cout << "Time to process a range of " 
                  << argc - 1 << " elements with std::vector : "
                  << endV - startV << " us\n";

        std::cout << "Time to process a range of "
                  << argc - 1 << " elements with std::deque : "
                  << endD - startD << " us\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
