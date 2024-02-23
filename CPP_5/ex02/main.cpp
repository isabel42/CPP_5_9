/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 11:44:15 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	Bureaucrat *buro = new Bureaucrat(149, "Buro");
	std::cout << std::endl << std::endl << "******** SHRUBBERY *********" << std::endl;
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm ("Shrubbery");
	std::cout << "------\n";
	buro->signForm(*shrubbery);
	try
	{	
		shrubbery->execute(*buro);
	}
	catch(AForm::Exception_parent &e)
	{
		std::cout << e.what();
	}
	std::cout << "------" << std::endl;
	delete shrubbery;

	std::cout << std::endl << std::endl << "******** ROBO *********" << std::endl;
	RobotomyRequestForm *robo = new RobotomyRequestForm ("Robo");
	std::cout << "------\n";
	buro->signForm(*robo);
	try
	{	
		robo->execute(*buro);
	}
	catch(AForm::Exception_parent &e)
	{
		std::cout << e.what();
	}
	std::cout << "------" << std::endl;
	delete robo;
	
	std::cout << std::endl << std::endl << "******** PRESI *********" << std::endl;
	PresidentialPardonForm *presi = new PresidentialPardonForm ("Presi");
	std::cout << "------\n";
	buro->signForm(*presi);
	try
	{	
		presi->execute(*buro);
	}
	catch(AForm::Exception_parent &e)
	{
		std::cout << e.what();
	}
	std::cout << "------" << std::endl;
	delete presi;
	delete buro;
}