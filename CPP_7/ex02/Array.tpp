/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:00:14 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/03 18:58:24 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "Array.hpp"

template<typename T> Array<T>::Array()
{
	this->elements = NULL;
}

Array::Array(std::size_t n)
{
	this->elements = new T[n];
}

Array::~Array()
{
	if (this->elements)
		delete [] this->elements;
	
}

Array & Array::operator=(const Array& src) {
	if (this == &src)
		return *this;
	if (this->size() != src.size())
	{
		if (this->elements != NULL)
			delete[] this->elements;
		this->elements = new T[src.size()];
	}
	for (std::size_t i = 0; i < this->_size; ++i)
	{
		this->elemenets[i] = src.elements[i];
	}
	return *this;
}

Array::Array(const Array& other) : elements(NULL) 
{
	*this = other;
}

std::size_t Array::size() const
{
	std::size size = 0;
	for (int i = 0;  this->elements[i]; ++i)
		size ++;
	return (size); 
}