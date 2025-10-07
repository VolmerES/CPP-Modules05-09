/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:37:30 by volmer            #+#    #+#             */
/*   Updated: 2025/10/07 16:52:37 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.tpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "Vector content: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	int value;
    std::cout << "Type value to search: ";
    std::cin >> value;
	
	try {
    std::vector<int>::iterator it = easyfind(v, value);
    std::cout << "Value found: " << *it << std::endl;
	} 
	catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
}