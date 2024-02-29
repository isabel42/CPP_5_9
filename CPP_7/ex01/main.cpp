/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/27 17:16:17 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void print(const T& a) {
	std::cout << a << std::endl;
}

template<typename T>
void increment(const T& a) {
	++(const_cast<T&>(a));
}

int main() {
	int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string arrString[4] = {"abc", "dfg", "hij", "klm"};

	std::cout << "INT ARRAY:\n" << std::endl;
	::iter(arrInt, 10, &print);

	std::cout << "\nINT ARRAY (after increment):\n" << std::endl;
	::iter(arrInt, 10, &increment);
	::iter(arrInt, 10, &print);

	std::cout << "\nSTRING ARRAY:\n" << std::endl;
	::iter(arrString, 4, &print);

	return 0;
}