/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/26 13:18:35 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

	if (argc == 1) {
		std::cout << "Error: no parameters\n" << "Usage: <program> <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
	
}