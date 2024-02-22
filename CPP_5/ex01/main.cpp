/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 15:42:02 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = new Bureaucrat();
	Bureaucrat *b2 = new Bureaucrat(50, "isa");
	Form *f1 = new Form();
	Form *f2 = new Form ("Andres", 49, 5);
	// try
	// {
	// 	Bureaucrat b3(249,"Bill");
	// }
	// catch (Bureaucrat::Exception &e)
	// {
	// 	std::cout << e.what();
	// }

	// try
	// {
	// 	Form f3("Miguel", 249, 5);
	// }
	// catch (Form::Exception_parent &e)
	// {
	// 	std::cout << e.what();
	// }

	// std::cout << *b1 << std::endl;
	// std::cout << *b2 << std::endl;
	std::cout << "------" << std::endl;
	std::cout << *f1 << std::endl;
	f1->beSigned(*b2);
	std::cout << *f1 << std::endl;
	b2->signForm(*f2);
	std::cout << "------" << std::endl;
	
	delete b1;
	delete b2;
	delete f1;
	delete f2;
}