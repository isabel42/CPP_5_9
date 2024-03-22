/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:29 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/22 14:16:47 by itovar-n         ###   ########.fr       */
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
	return (*this);
}

RPN::RPN (RPN const & src)
{
	*this = src;
}

void RPN::add()
{
	int joker;
	
	joker = this->numbers.top();
	this->numbers.pop();
	joker = this->numbers.top() + joker;
	this->numbers.pop();
	this->numbers.push(joker);	
}

void RPN::subs()
{
	int joker;
	
	joker = this->numbers.top();
	this->numbers.pop();
	joker = this->numbers.top() - joker;
	this->numbers.pop();
	this->numbers.push(joker);	
}

void RPN::mult()
{
	int joker;
	
	joker = this->numbers.top();
	this->numbers.pop();
	joker = joker * this->numbers.top();
	this->numbers.pop();
	this->numbers.push(joker);
}

void RPN::div()
{
	int joker;

	joker = this->numbers.top(); 
	if (joker == 0)
		throw (std::runtime_error("Error"));
	this->numbers.pop();
	joker = this->numbers.top() / joker;
	this->numbers.pop();
	this->numbers.push(joker);
}
void RPN::ResolveStack(const char c)
{
	if (c == '+')
		this->add();
	else if (c == '-')
		this->subs();
	else if (c == '*')
		this->mult();
	else if (c == '/')
		this->div();
}

void RPN::TreatInput(std::string const &input)
{
	bool flag_digit = false;
	int sign = 1;
	for (std::size_t i = 0; i < input.size(); i++ )
	{
		if (isspace(input[i]))
		{
			flag_digit = false;
			sign = 1;
			continue ;
		}
		else if (isdigit(input[i]))
		{
			if(flag_digit)
				throw (std::runtime_error("Error"));
			this->numbers.push((input[i] - '0') * sign);
			sign = 1;
			flag_digit = true;
		}
		else if (!flag_digit && input[i] == '-' && input[i+1] && isdigit(input[i+1]))
		{
			sign = -1;
			continue;	
		}
		else if ((input[i] == '+' || input[i] == '-' || input [i] == '/' || input[i] == '*') && this->numbers.size() > 1)
		{
			this->ResolveStack(input[i]);
			flag_digit = false;
		}
		else
		{
			throw (std::runtime_error("Error"));
		}
	}
	if (this->numbers.size() > 1 )
			throw (std::runtime_error("Error"));
		
}

int RPN::getTop()
{
	return (this->numbers.top());
}