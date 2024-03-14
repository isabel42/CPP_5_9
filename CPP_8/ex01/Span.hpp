/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:21:19 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/14 12:23:13 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>


class Span
{
	private:
		unsigned int _n;
		std::vector<int> _entiers;
	
	public:
		~Span();
		Span(unsigned int n);
		Span (Span const &src);
		Span & operator=(Span const &src);
		
		unsigned int getSize() const;
		std::vector<int> get_entiers() const;
		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		void addRange(int first, int last);
		void addVector(std::vector<int> src);
};

#endif