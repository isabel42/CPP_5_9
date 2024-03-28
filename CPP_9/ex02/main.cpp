/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:53 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/28 15:03:20 by itovar-n         ###   ########.fr       */
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
		PmergeMe input(argc, argv);
		std::vector <int> input_vector = input.getSimpleVector();
		
		std::cout << "Before:\t";
		for (std::vector<int>::iterator it = input_vector.begin(); it != input_vector.end(); it++) 
		{ 
			std::cout << " " << *it << " "; 
		}
		std::cout << std::endl << std::endl;
		
		clock_t start_l = clock();
		input.list_cut(input.getSimpleList());
		clock_t end_l1 = clock();
		input.MergeList();
		clock_t end_l2 = clock();
		 double time_l1 = static_cast<double>(end_l1 - start_l) / CLOCKS_PER_SEC * 1000;
		 double time_l2 = static_cast<double>(end_l2 - end_l1) / CLOCKS_PER_SEC * 1000;
		
		clock_t start_v = clock();
		input.vector_cut(input.getSimpleVector());
		clock_t end_v1 = clock();
		input.MergeVector();
		clock_t end_v2 = clock();
		double time_v1 = static_cast<double>(end_v1 - start_v) / CLOCKS_PER_SEC * 1000;
		double time_v2 = static_cast<double>(end_v2 - end_v1) / CLOCKS_PER_SEC * 1000;
		
		std::cout << "After:\t";
		input.printNestedVector();
		std::cout << std::endl << "----LIST----" << std::endl;
		std::cout << "Time to process a range of " << input_vector.size() << " elements with std::list container: " << std::endl;
		std::cout << "   Sorting:" << time_l1 << " us" << std::endl;
		std::cout << "   Data management part (merge):" << time_l2 << " us" << std::endl;
		std::cout << std::endl << "----VECTOR----" << std::endl;
		std::cout << "Time to process a range of " << input_vector.size() << " elements with std::vector container: " << std::endl;
		std::cout << "   Sorting:" << time_v1 << " us" << std::endl;
		std::cout << "   Data management part (merge):" << time_v2 << " us" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}