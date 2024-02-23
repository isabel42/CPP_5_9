/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:17 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:20:41 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm () : AForm("Default RobotomyRequestForm", 72 , 45)
{
	std::cout << "RobotomyRequest " << *this << "has defaulty been constructed." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm (std::string target) :  AForm("Shrub Parent", 72, 45), _target(target)
{
	std::cout << "RobotomyRequest " << *this << "has been constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const & src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
	std::cout << "RobotomyRequestForm " << *this << "got created as a copy from " << src << "." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << *this << " has been destroyed." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

const char* RobotomyRequestForm::Exception_RobotomyFailed::what() const throw()
{
	return ("Robotomy Failed!");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
	
	std::cout << "Making some drilling noises." << std::endl;
	int success = std::rand() % 2;
	if (success == 1)
		std::cout << this->_target << "has been robotomized." << std::endl;
	else
		throw (RobotomyRequestForm::Exception_RobotomyFailed());
}
