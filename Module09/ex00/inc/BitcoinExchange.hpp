/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:37:50 by volmer            #+#    #+#             */
/*   Updated: 2025/11/03 18:09:56 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _rates;
		
		double		getRateForDate(const std::string & date) const;
		static bool	isValidDate(const std::string & date);
		static bool	processInputFile(const std::string & line,
                               std::string & date, double& value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange& operator=(const BitcoinExchange & other);
		~BitcoinExchange();

		void		loadDatabase(const std::string & datapath);
		void		handleInput(const std::string & inputpath) const;
};