/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:53 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:11:21 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	try
	{	
		PmergeMe test(argc, argv);
		test.list_cut(test.getSimpleList());
		test.printNestedList();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}