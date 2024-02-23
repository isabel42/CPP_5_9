/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:17 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:36:08 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm () : AForm("Default PresidentialPardonForm", 25 , 5)
{
	std::cout << "RobotomyRequest " << *this << "has defaulty been constructed." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm (std::string target) :  AForm("Shrub Parent", 25, 5), _target(target)
{
	std::cout << "RobotomyRequest " << *this << "has been constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const & src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
	std::cout << "PresidentialPardonForm " << *this << "got created as a copy from " << src << "." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << *this << " has been destroyed." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;

}
