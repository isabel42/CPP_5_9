/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:26:48 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/26 18:22:46 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "RPN.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	
	RPN test;
	
	try
	{	
		test.TreatInput(argv[1]);
		std::cout << test.getTop() << std::endl;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}