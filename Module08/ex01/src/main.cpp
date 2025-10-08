/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:04:29 by volmer            #+#    #+#             */
/*   Updated: 2025/10/08 13:10:00 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>

int main()
{
	std::cout << "Test Span with addNumber" << std::endl;
    try {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	std::cout << "Test Span with addRange" << std::endl;
	try {
	    Span spr(10000);
	
	    std::vector<int> src;
	    src.reserve(10000);
	    for (int i = 0; i < 10000; ++i)
	        src.push_back(i);
	
	    spr.addRange(src.begin(), src.end());
	    std::cout << "Shortest span: " << spr.shortestSpan() << std::endl;
	    std::cout << "Longest span: "  << spr.longestSpan()  << std::endl;
	}
	catch (const std::exception& e) {
	    std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Test Span with addRange (overflow expected)" << std::endl;
	try {
	    Span sprSmall(5000);
	
	    std::vector<int> big;
	    big.reserve(10000);
	    for (int i = 0; i < 10000; ++i)
	        big.push_back(i);
	
	    sprSmall.addRange(big.begin(), big.end());
	    std::cout << "Should not print" << std::endl;
	}
	catch (const std::exception& e) {
	    std::cerr << "Error (ok): " << e.what() << std::endl;
	}
	
    return (0);
}
