/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:37 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/26 17:44:07 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"


Serializer::Serializer()
{
	std::cout << "Default constructor called." << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called." << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
	std::cout << "Constructor based con ref called." << std::endl;
	*this = src;
}

Serializer & Serializer::operator=(Serializer const &src)
{
	std::cout << "Surcharge operator = called." << std::endl;
	(void) src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}