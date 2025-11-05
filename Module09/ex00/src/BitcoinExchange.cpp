/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:11:15 by volmer            #+#    #+#             */
/*   Updated: 2025/11/05 13:36:00 by volmer           ###   ########.fr       */
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

void BitcoinExchange::handleInput(const std::string & inputpath) const {}


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
    // 1) Si la línea está vacía, no hay nada que procesar → return false (silencioso).
	if (line.empty())
		return (false);
		
	size_t bar = line.find('|');
	if (bar == std::string::npos)
	{
  		std::cerr << "Error: bad input => " << line << std::endl;
  		return false;
	}
    // 3) Separar en left (antes de '|') y right (después de '|').
	std::string left;
	std::string right;
	
	left = line.substr(0, bar);
	right = line.substr(bar + 1);
	
    // 4) trim() a ambos lados para eliminar espacios.
	ft_trim(left);
	ft_trim(right);

	
    // 5) Si es la cabecera "date | value", ignorar (return false sin error).
    // 6) Validar formato de fecha con isValidDate(left). Si falla → "Error: bad input => <line>".
	if (!isValidDate(left))
		return (false);
    // 7) Parsear el valor (double) desde right con stringstream.
    //    - Si falla la conversión → "Error: bad input => <line>".
    //    - Comprobar que no haya basura extra tras el número (saltando espacios).
    // 8) Comprobar reglas del enunciado:
    //    - value < 0 → "Error: not a positive number."
    //    - value > 1000 → "Error: too large a number."
    // 9) Si todo OK:
    //    - date = left; value = número leído; return true.										
}