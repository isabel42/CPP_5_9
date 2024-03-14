/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:57:50 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/14 13:52:55 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{

	Span test = Span(15000);

	std::cout << std:: endl << "***********TESTING ADDNUMBER************:" << std::endl;
	try
	{	
		std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;
		test.addNumber(0);
		std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;
		std::cout<< test.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::cout<< test.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << std:: endl << "***********TESTING ADDRRANGE************:" << std::endl;
	try
	{	
		std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;
		test.addRange(150 , 900);
		std::cout<< "Longest Span is: " << test.longestSpan() << "."<< std::endl;
		std::cout<< "Shortest Span is: " << test.shortestSpan() << "."<< std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	};
	

	std::cout << std:: endl << "***********TESTING ADDVECTOR************:" << std::endl;
	try
	{	
		std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;
		test.addVector(test.get_entiers());
		std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;
		std::cout<< "Longest Span is: " << test.longestSpan() << "."<< std::endl;
		std::cout<< "Shortest Span is: " << test.shortestSpan() << "."<< std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Size of the vector: " << test.getSize() << "." << std::endl;

}