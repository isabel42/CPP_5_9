/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/04 11:42:03 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = new Bureaucrat();
	Bureaucrat *b2 = new Bureaucrat(50, "isa");
	
	std::cout << "------" << std::endl;
	Form *f1 = new Form();
	std::cout << *f1 << std::endl;
	f1->beSigned(*b2);
	std::cout << *f1 << std::endl;
	
	std::cout << "------" << std::endl;
	Form *f2;
	try
	{
		f2 = new Form ("Andres", 449, 5);
		b2->signForm(*f2);
	}
	catch (Form::Exception_parent &e)
	{
		std::cout << e.what();
	}
	
	std::cout << "------" << std::endl;
	delete b1;
	delete b2;
	delete f1;
	delete f2;
}