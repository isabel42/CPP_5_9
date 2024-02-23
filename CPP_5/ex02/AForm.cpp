/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:17 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:47:31 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm () : _name ("Default"), _signed(0), _grade_sign(150), _grade_exec(150)
{
	std::cout << "A default AForm has been constructed." << std::endl;
}
AForm::AForm (std::string name, int grade_to_sign, int grade_to_exec) :  _name(name), _signed(0),_grade_sign(grade_to_sign), _grade_exec(grade_to_exec)
{
	if (_grade_sign > 150 || _grade_exec > 150)
		throw(AForm::GradeTooLowException());
	if (_grade_sign < 1 || _grade_exec < 1)
		throw(AForm::GradeTooHighException());
	std::cout << *this << " has been constructed." << std::endl;
}

AForm::AForm (AForm & src) : _name(src.getName()), _signed(src.getSign()), _grade_sign(src.getSign()), _grade_exec(src.getGradeExec())
{
	std::cout << *this << "got created as a copy from " << src << "." << std::endl;
}

AForm::~AForm()
{
	std::cout << *this << " has been destroyed." << std::endl;
}

AForm & AForm::operator=(AForm &src)
{
	this->_signed = src.getSign();
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSign() const
{
	return (this->_signed);
}

int AForm::getGradeSign() const
{
	return (this->_grade_sign);
}

int AForm::getGradeExec() const
{
	return (this->_grade_exec);
}

const char* AForm::Exception_parent::what() const throw()
{
	return ("FormException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form cannot have a grade > 150!\n");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form cannot have get a grade < 1!\n");
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("Form is unsigned and cannot be executed!\n");
}

void AForm::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->getGradeSign())
		throw(AForm::GradeTooLowException());
	this->_signed = true;
}

void AForm::checkExec(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw (AForm::UnsignedFormException());
	if (executor.getGrade() > this->getGradeExec())
		throw(AForm::GradeTooLowException());
}

std::ostream & operator<<(std::ostream &o, AForm const &src)
{
	o << "Form: " << src.getName() << " is " << src.getSign() << " signed with a grade need to sign: " << src.getGradeSign() << " , a grade needed to execute: " << src.getGradeExec();
	return (o);
}