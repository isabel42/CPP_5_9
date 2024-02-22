/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 18:20:55 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// Bureaucrat *b1 = new Bureaucrat();
	Bureaucrat *b2 = new Bureaucrat(15, "isa");
	// Form *f1 = new AForm();
	ShrubberyCreationForm *shubbyf1 = new ShrubberyCreationForm("Andres");
	ShrubberyCreationForm *shubbyf2 = new ShrubberyCreationForm(*shubbyf1);
	// Form *f2 = new AForm ("Andres", 49, 5);
	// // try
	// // {
	// // 	Bureaucrat b3(249,"Bill");
	// // }
	// // catch (Bureaucrat::Exception &e)
	// // {
	// // 	std::cout << e.what();
	// // }

	// // try
	// // {
	// // 	Form f3("Miguel", 249, 5);
	// // }
	// // catch (Form::Exception_parent &e)
	// // {
	// // 	std::cout << e.what();
	// // }

	// // std::cout << *b1 << std::endl;
	// // std::cout << *b2 << std::endl;
	// std::cout << "------" << std::endl;
	// std::cout << *f1 << std::endl;
	// f1->beSigned(*b2);
	// std::cout << *f1 << std::endl;
	// b2->signForm(*f2);
	// std::cout << "------" << std::endl;
	b2->signForm(*shubbyf1);
	b2->signForm(*shubbyf2);
	try
	{	
		shubbyf1->execute(*b2);
	}
	catch(AForm::Exception_parent &e)
	{
		std::cout << e.what();
	}
	
	// delete b1;
	delete b2;
	// delete f1;
	// delete f2;
}