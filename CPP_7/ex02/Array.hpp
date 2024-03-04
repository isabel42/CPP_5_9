/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:23:52 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/27 17:48:48 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array 
{
	private: 
		T* _elements;
		std::size_t _size;

	public: 
		Array();
		~Array();
		Array(std::size_t n);
		Array(Array const & src);
		Array<T> & operator=(Array<T> const & src);

		std::size_t size() const;
		T & operator[](std::size_t i);

		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif