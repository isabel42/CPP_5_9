/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/27 17:12:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* arr, std::size_t lenght, void (*f)(const T&)) {
	for (std::size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}

#endif
