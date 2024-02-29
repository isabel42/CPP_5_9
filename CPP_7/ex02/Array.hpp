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
		T* elements;

	public: 
		Array();
		~Array();
		// Array(std::size_t n);
		// Array(Array const & src);
		// Array operator=(Array const & src);

		// int size() const;
};


#endif