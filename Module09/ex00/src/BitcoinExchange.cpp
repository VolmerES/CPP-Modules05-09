/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:11:15 by volmer            #+#    #+#             */
/*   Updated: 2025/11/05 16:05:29 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return (*this);
}

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

bool BitcoinExchange::isValidDate(const std::string & date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string	yearSTR;
	std::string	monthSTR;
	std::string	daySTR;


	yearSTR = date.substr(0, 4);
	monthSTR = date.substr(5, 2);
	daySTR = date.substr(8, 2);

	std::stringstream ssYear(yearSTR);
	std::stringstream ssMonth(monthSTR);
	std::stringstream ssDay(daySTR);

	int year, month, day;
	
 	if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day))
    	return (false);
	
	if (month < 1 || month > 12 || day < 1)
		return (false);
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
   		daysInMonth[1] = 29;
	
	if (day > daysInMonth[month - 1])
		return (false);

	return (true);
}
double BitcoinExchange::getRateForDate(const std::string & date) const
{
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it != _rates.end())
		return (it->second);

	it = _rates.lower_bound(date);
	if (it == _rates.begin())
		throw std::runtime_error("Error: no rate avaliable before" + date);
	it--;
	return (it->second);
}

void BitcoinExchange::handleInput(const std::string & inputpath) const
{
	std::ifstream inputFile(inputpath.c_str());

	if (!inputFile)
	{
		std::cerr << "Error: could not open file." << std::endl;
        return;
	}

	std::string line;
	std::string date;
	double		value;

	while (std::getline(inputFile, line))
	{
		if (!processInputFile(line, date, value))
		{
			continue;
		}
		try
		{
			double	rate = getRateForDate(date);
			double	result = value * rate;
			std::cout << date << "->" << value << "=" << result << std::endl;
		}
		catch (const std::exception & e)
		{
				std::cerr << e.what() << std::endl;
		}
	}
	inputFile.close();
}


static std::string ft_trim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(start, end - start + 1);
}

bool BitcoinExchange::processInputFile(const std::string & line, std::string & date, double& value) 
{
	if (line.empty())
		return (false);
		
	size_t bar = line.find('|');
	if (bar == std::string::npos)
	{
  		std::cerr << "Error: bad input => " << line << std::endl;
  		return false;
	}
	std::string left;
	std::string right;
	
	left = line.substr(0, bar);
	right = line.substr(bar + 1);
	ft_trim(left);
	ft_trim(right);
	if (left == "date" && right == "value")
		return (false);
	if (!isValidDate(left))
	{
		std::cerr << "Error: no valid date => " << line << std::endl;
		return (false);
	}

	std::stringstream ss(right);
	double val;
	if (!(ss >> val))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
        return (false);
	}
	std::string trash;
	ss >> trash;
	if (!trash.empty())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
        return false;
	}
	    if (val < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    
    if (val > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
	date = left;
	value = val;
    return (true);								
}