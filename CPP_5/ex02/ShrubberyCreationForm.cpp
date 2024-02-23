/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:17 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:15:30 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("Default ShrubberyCreationForm", 145 , 137)
{
	std::cout << "ShrubberyCreation " << *this << "has defaulty been constructed." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm (std::string target) :  AForm("Shrub Parent", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreation " << *this << "has been constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const & src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
	std::cout << "ShrubberyCreationForm " << *this << "got created as a copy from " << src << "." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << *this << " has been destroyed." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

const char* ShrubberyCreationForm::Exception_CannotOpen::what() const throw()
{
	return ("Could not open outputfile");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
	std::string	tree = 
		"     ccee88oo          \n"
		"  C8O8O8Q8PoOb o8oo    \n"
		" dOB69QO8PdUOpugoO9bD  \n"
		"CgggbU8OU qOp qOdoUOdcb\n"
		"   6OuU  /p u gcoUodpP \n"
		"      \\\\//  /douUP   \n"
		"        \\\\////       \n"
		"         |||/\\        \n"
		"         |||\\/        \n"
		"         |||||         \n"
		"         |||||         \n"
		"         |||||         \n"
		"		 |||||||  		\n"
		"  .....\\//||||\\....  \n";

	std::string file_name = this->_target + "_shubbery";
	std::ofstream ofs(file_name);
	if (!ofs.is_open())
		throw(ShrubberyCreationForm::Exception_CannotOpen());
	ofs << tree;
}
