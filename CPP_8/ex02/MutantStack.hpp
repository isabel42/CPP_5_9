/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:42:21 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/14 16:25:44 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iteratori;
		typedef typename std::stack<T>::container_type::const_iterator	const_iteratori;

		iteratori begin();
		iteratori end();
		const_iteratori begin() const;
		const_iteratori end() const;
			
};

#include "MutantStack.tpp"

#endif