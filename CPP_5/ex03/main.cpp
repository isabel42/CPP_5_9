/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/03 16:57:13 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << std::endl;
	Bureaucrat *buro = new Bureaucrat(149, "Buro");
	Bureaucrat *best = new Bureaucrat(1, "Best");
	Intern *stag = new Intern();
	AForm *shubi;
	try
	{
		shubi = stag->makeForm("shrubbery creation", "Isa");
		best->signForm(*shubi);
		best->executeForm(*shubi);
	}
	catch(Intern::Exception_FormNotFound &e)
	{
		std::cerr << e.what() << '\n';
	}
	delete buro;
	delete best;
	delete stag;
}