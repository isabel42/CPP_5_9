/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/27 17:01:06 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template < typename T >

void swap (T &a, T &b)
{
	T joker = a;
	a = b;
	b = joker;
}

template < typename T >
const T & max (const T &a, const T &b)
{
	return (a > b ? a : b);
}

template < typename T >
const T & min (const T &a, const T &b)
{
	return (a < b ? a : b);
}

#endif
