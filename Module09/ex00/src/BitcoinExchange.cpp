/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:11:15 by volmer            #+#    #+#             */
/*   Updated: 2025/11/03 18:45:09 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string & datapath) 
{
	std::ifstream datacsv(datapath.c_str());
	if (!datacsv) 
	{
		std::cerr << "Error: Cannot open database" << std::endl;
		return;
	}

	_rates.clear();

	std::string line;
	bool header = true;
	while (std::getline(datacsv, line))
	{
		if (header)
		{
			header = false;
			continue;
		}
		if (line.empty())
			continue;
			
		size_t comma = line.find(",");
		if (!comma)
		{
			std::cerr << "Error: Bad format on data.csv" << std::endl;
			continue;
		}
		std::string date;
		std::string valueSTR;
		
		date = line.substr(0, comma);
		valueSTR = line.substr(comma + 1);
		if (!isValidDate(date))
			continue;

		float valueFl;
		std::stringstream ssvalue(valueSTR);
		if (!(ssvalue >> valueFl))
		{
			std::cerr << "Error: Invalid value" << std::endl;
			continue;
		}
		_rates[date] = valueFl;
	}
	datacsv.close();
}

void BitcoinExchange::handleInput(const std::string & inputpath) const {}

double BitcoinExchange::getRateForDate(const std::string & date) const {}

bool BitcoinExchange::isValidDate(const std::string & date) {}

bool BitcoinExchange::processInputFile(const std::string & line,
                                       std::string & date, double& value) {}