/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:57:50 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/13 14:14:13 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>

int main()
{
	try
	{
		std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
		std::cout << *easyfind(ar, 1) << std::endl;
	}
	catch ( const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int> v;
		for (int i = 1; i <= 5; i++) 
				v.push_back(i); 
		std::cout << *easyfind(v, 1) << std::endl;
	}
	catch ( const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}