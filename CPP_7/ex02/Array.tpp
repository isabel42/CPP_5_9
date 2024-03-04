/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:00:14 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/04 17:36:23 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T> 
Array<T>::Array()
{
	this->_elements = NULL;
	this->_size = 0;
}

template<typename T> 
Array<T>::Array(std::size_t n) : _elements(new T[n]), _size(n)
{
}

template<typename T> 
Array<T>::~Array()
{
	if (this->_elements)
		delete [] this->_elements;
	
}

template<typename T> 
Array<T> & Array<T>::operator=(Array<T> const & src)
{
	if (this == &src)
		return *this;
	if (this->_size != src._size)
	{
		if (this->_elements != NULL)
			delete[] this->_elements;
		this->_elements = new T[src._size];
	}
	for (std::size_t i = 0; i < src._size; ++i)
	{
		this->_elements[i] = src._elements[i];
	}
	return *this;
}

template<typename T> 
Array<T>::Array(const Array& other) : _elements(other._elements) , _size(other._size)
{
	*this = other;
}
template<typename T> 
std::size_t Array<T>::size() const
{
	return (this->_size); 
}

template<typename T> 
const char* Array<T>::InvalidIndexException::what() const throw()
{
	return ("Wrong index");
}

template<typename T> 
T & Array<T>::operator[](std::size_t i) 
{
	if (i > this->size() || i < 0)
		throw(Array<T>::InvalidIndexException());
	else
		return (this->_elements[i]);
}
