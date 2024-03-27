/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:53 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/27 16:16:36 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::list <int> sol;
	if (argc < 2)
		return -1;
	try
	{	
		PmergeMe test(argc, argv);
		test.list_cut(test.getSimpleList());
		test.printNestedList();
		test.Merge();
		std::cout << std::endl;
		test.printNestedList();
		std::list <int> sol = test.getSimpleList();
		for(std::list<int>::iterator it = sol.begin(); it != sol.end(); it++)
			std::cout << " " << *it;
		std::list<int>::iterator single_list_itr; 
;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}