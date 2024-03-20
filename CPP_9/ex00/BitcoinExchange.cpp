/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:26:00 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/20 17:12:11 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &file)
{
	std::ifstream MyReadFile(file);
	std::string myText;
	std::getline (MyReadFile, myText); //Skype header line
	while (std::getline (MyReadFile, myText)) 
	{
		std::size_t commapos = myText.find(',');
		if (commapos == std::string::npos)
		{
			std::cerr << "Error. Invalid format in data base line: " << myText << std::endl;
			continue;
		}

		std::string date = myText.substr(0, commapos);
		std::string price = myText.substr(commapos + 1);
		
		double rate;
		std::istringstream price_stream(price);
		if (!(price_stream >> rate))
		{
			std::cerr << "Error. Invalid format in data base line: " << myText << std::endl;
			continue;
		}
		this->data_[date] = rate;
	}
}

bool BitcoinExchange::ValueOk(const double &value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large number" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::DateOk(const std::string &date)
{
	int year, month, day;
	char delim1, delim2;
	std::istringstream date_stream(date);
	if (!(date_stream >> year >> delim1 >> month >> delim2 >> day))
	{
		std::cerr << "Error: Could not parse => " << date << std::endl;
		return false;
			
	}
	if (delim1 != '-' || delim2 != '-' || month > 12 || month < 1 || day > 31 || day < 1 
		|| (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		|| (day > 29 && month == 2)
		|| (day > 28 && (month == 2 && (year % 4 != 0 || (year % 4 == 0 && year % 100 == 0 && year % 400 != 0)))))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::GetOutput(const std::string &file)
{
	std::ifstream MyReadFile(file);
	std::string line;
	std::string date;
	char delim;
	double nb;
	
	std::getline (MyReadFile, line); //Skype header line
	while (std::getline (MyReadFile, line)) 
	{
		std::istringstream line_stream(line);
		if (!(line_stream >> date >> delim >> nb))
		{
			std::cerr << "Error: Could not parse => " << line << std::endl;
		}
		if (!DateOk(date) || !ValueOk(nb))
			continue ;
		if (delim != '|')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
		
		std::map<std::string, double>::iterator it = this->data_.upper_bound(date);
		// std::cout << date << std::endl; //" => " << nb << " = " <<  nb * it->second << std::endl;
		std::cout << date << " => " << nb << " = " <<  it->second << std::endl;
}