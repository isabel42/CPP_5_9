/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:25:27 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/13 17:24:45 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::~Span()
{
}

Span::Span (unsigned int n): _n(n), _entiers(0)
{
}

Span::Span (Span const &src)
{
	*this = src;
}

Span & Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_n = src._n;
		_entiers = src._entiers;
	}
	return (*this);
}

void Span::addNumber(int nb)
{
	if (this->_entiers.size() < this->_n)
		this->_entiers.push_back(nb); 
	else
		throw (std::out_of_range("vector is already ful"));
}

unsigned int Span::getSize() const
{
	return (this->_entiers.size());
}

unsigned int Span::longestSpan() const
{
	if (this->getSize() < 2)
		throw (std::length_error("vector size is 1, cannot have a span"));
	std::vector<int> cp_entiers;
	cp_entiers = this->_entiers;
	std::sort(cp_entiers.begin(), cp_entiers.end());
	return (*(cp_entiers.end() - 1) - *cp_entiers.begin());
}

unsigned int Span::shortestSpan() const
{
	if (this->getSize() < 2)
		throw (std::length_error("vector size is 1, cannot have a span"));
	int ret;
	std::vector<int> cp_entiers;
	cp_entiers = this->_entiers;
	std::sort(cp_entiers.begin(), cp_entiers.end());
	ret = *(cp_entiers.begin() + 1) - *cp_entiers.begin();
	for (std::vector<int>::iterator it = cp_entiers.begin() + 1; it < cp_entiers.end() - 1; it++)
	{
		if (ret > *(it + 1)  - *it)
			ret = *(it + 1)  - *it;
	}
	return (ret);
}