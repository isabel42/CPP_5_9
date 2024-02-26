/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:37 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/20 16:05:22 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called." << std::endl;
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Constructor based con ref called." << std::endl;
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "Surcharge operator = called." << std::endl;
	(void) src;
	return (*this);
}

void ScalarConverter::convert(const std::string &argv)
{
	std::string toChar = "";
	
	int toInt = 0;
	
	if (argv.size() == 1 && std::isprint(argv[0]) && !std::isdigit(argv[0])) {
		toChar = argv[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}

	float toFloat = 0;
	double toDouble = 0;
	std::string specialTypes[6] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};

	for (int i = 0; i < 6; ++i) 
	{
		if (argv == specialTypes[i]) {
			toChar = "imposible"; break;
		}
	}

	toInt = std::atoi(argv.c_str()); // c_str returns argv with \0 at the end. 

	//checks if it is a float with f at the end.
	if (argv[argv.length() - 1] == 'f') {
		toFloat = std::atof(argv.c_str());
		toDouble = static_cast<double>(toFloat);
	} 
	else {
		toDouble = std::atof(argv.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	// filling ToChar if is not impossible. 
	if (toChar == "" && std::isprint(toInt)) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} else if (toChar == "") {
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	
	if (toChar == "imposible") {
		std::cout << "int: imposible" << std::endl;
	} else {
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "imposible" && toFloat == 0) {
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	} else {
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0) {
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} else {
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}

