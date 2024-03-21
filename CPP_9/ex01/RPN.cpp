/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:29 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/21 22:00:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN & RPN::operator=(RPN const & src)
{
	this->numbers = src.numbers;
	this->sign = src.sign;
	return (*this);
}

RPN::RPN (RPN const & src)
{
	*this = src;
}

int RPN::TreatInput(std::string const &input)
{
	bool flag_digit = false;
	bool flag_sign = false;
	bool flag_block = false;
	for (std::size_t i = 0; input[i]!=std::string::npos; i++ )
	{
	if (isspace(input[i]))
	{
		flag_digit = false;
		flag_sign = false;
		continue ;
	}
	if (flag_digit || flag_sign)
		throw (std::runtime_error("Syntax error"));
	if (isdigit(input[i]))
	{
		if (flag_block)
		{
			res = ...
			flag_block = false;
		}
		else
			insert into digit stack
		flag_digit = true;
	}
	if (input[i] == '+' || input[i] == '-' || input [i] == '/' || input[i] == '*')
	{
		insert into sign stack
		flag_digit = true;
		flag_block = true;
	}
		std::cout << input[i]<< "*";
	}
	return res;
}
