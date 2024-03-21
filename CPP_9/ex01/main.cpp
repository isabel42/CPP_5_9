/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:26:48 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/21 20:47:10 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "RPN.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	
	int t = 0;
	RPN test;
	// RPN test(void);
	
	t = test.TreatInput(argv[1]);
	std::cout << t << std::endl;

	// BitcoinExchange test("data.csv");
	// test.GetOutput(argv[1]);
	
	// std::stack<int> numbers;
	// std::stack<char> sign;

	// int test;
	// test = std::atoi(argv[1]);
	// if (test >= 0 && test < 10)
	// 	std::cout << "yes" << std::endl;
	// else
	// 	std::cout << "noooooo" << std::endl;
	
}