/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:39:48 by volmer            #+#    #+#             */
/*   Updated: 2025/11/05 16:13:01 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../inc/BitcoinExchange.hpp"
 
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Not enough arguments" << std::endl;
		return (1);
	}

	BitcoinExchange BTC;
	
	BTC.loadDatabase("data.csv");
	BTC.handleInput(argv[1]);

	return (0);
}
