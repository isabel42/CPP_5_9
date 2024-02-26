/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:37 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 12:54:53 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Constructor based con ref called." << std::endl;
	*this = src;
}

Intern & Intern::operator=(Intern const &src)
{
	*this = src;
	std::cout << "Surcharge operator = called." << std::endl;
	return (*this);
}

AForm * Intern::makeForm(std::string form_name, std::string form_target)
{
	AForm *(*fct[3])(std::string target) = {new_robo, new_presi, new_shrub};
	std::string	name[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	AForm *result = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form_name == name[i])
			result = fct[i](form_target);
	}
	if (result)
		std::cout << "Intern has created " << *result << std::endl;
	else
		throw (Intern::Exception_FormNotFound());
	return (result);
}

static AForm	*new_shrub(std::string target)
{
	AForm	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

static AForm *new_robo(std::string target)
{
	AForm *robo = new RobotomyRequestForm(target);
	return (robo);
}

static AForm *new_presi(std::string target)
{
	AForm *presi = new PresidentialPardonForm(target);
	return (presi);
}


// ---------------------- InternException Functions -----------------------

const char* Intern::Exception_FormNotFound::what() const throw()
{
	return ("Error 404: Form not found");
}






