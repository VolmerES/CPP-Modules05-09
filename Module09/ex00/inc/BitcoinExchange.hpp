/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:37:50 by volmer            #+#    #+#             */
/*   Updated: 2025/11/03 15:39:44 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange& operator=(const BitcoinExchange & other);
		~BitcoinExchange();
};