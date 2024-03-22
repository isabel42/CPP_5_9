/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:29 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/21 22:15:09 by itovar-n         ###   ########.fr       */
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
	int res = 0;
	for (std::size_t i = 0; i < input.size(); i++ )
	{
		if (isspace(input[i]))
		{
			flag_digit = false;
			flag_sign = false;
			continue ;
		}
		else if (flag_digit || flag_sign)
			throw (std::runtime_error("Syntax error"));
		else if (isdigit(input[i]))
		{
			if (flag_block)
			{
				res = 10 + res;
				flag_block = false;
			}
			else
				this->numbers.push(input[i] - '0');
			flag_digit = true;
		}
		else if (input[i] == '+' || input[i] == '-' || input [i] == '/' || input[i] == '*')
		{
			this->sign.push(input[i]);
			flag_digit = true;
			flag_block = true;
		}
		else
		{
			throw (std::runtime_error("Syntax error"));
		}
	}
	return res;
}
