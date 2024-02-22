/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 15:03:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = new Bureaucrat();
	Bureaucrat *b2 = new Bureaucrat(10, "isa");
	try
	{
		Bureaucrat b3(49,"Bill");
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what();
	}

	std::cout <<  b1->getGrade() << std::endl;
	std::cout <<  b1->getName() << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *b2 << std::endl;
	delete b1;
	delete b2;
}