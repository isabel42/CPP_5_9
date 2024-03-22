/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:56 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/22 16:01:57 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::string joker;
	for (int i = 1; i < argc ; i++) 
	{
		joker = argv[i];
		for (std::size_t j = 0; j < joker.size(); j++)
		{
			if (!isdigit(joker[j]))
				throw(std::logic_error("Program only accepts numbers."));
		}
		if (joker.compare("2147483647") > 0 && joker.size() >= 10)
			throw(std::logic_error("Number is out of int scope."));
		this->_vector.push_back(std::atoi(argv[i]));
		this->_list.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe (PmergeMe &src)
{
	*this = src;
}


PmergeMe & PmergeMe::operator=(PmergeMe &src)
{

	this->_list = src._list;
	this->_vector = src._vector;
	return (*this);
}

std::list <int> PmergeMe::getList()
{
	return(this->_list);
}

std::vector <int> PmergeMe::getVector()
{
	return(this->_vector);
}
// PmergeMe::FJList()
// {
	
// }