/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:17 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 15:43:01 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form () : _name ("Default"), _signed(0), _grade_sign(150), _grade_exec(150)
{
	std::cout << "A default Form has been constructed." << std::endl;
}
Form::Form (std::string name, int grade_to_sign, int grade_to_exec) :  _name(name), _signed(0),_grade_sign(grade_to_sign), _grade_exec(grade_to_exec)
{
	if (_grade_sign > 150 || _grade_exec > 150)
		throw(Form::GradeTooLowException());
	if (_grade_sign < 1 || _grade_exec < 1)
		throw(Form::GradeTooHighException());
	std::cout << *this << " has been constructed." << std::endl;
}

Form::Form (Form & src) : _name(src.getName()), _signed(src.getSign()), _grade_sign(src.getSign()), _grade_exec(src.getGradeExec())
{
	std::cout << *this << "got created as a copy from " << src << "." << std::endl;
}

Form::~Form()
{
	std::cout << *this << " has been destroyed." << std::endl;
}

Form & Form::operator=(Form &src)
{
	this->_signed = src.getSign();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_signed);
}

int Form::getGradeSign() const
{
	return (this->_grade_sign);
}

int Form::getGradeExec() const
{
	return (this->_grade_exec);
}

const char* Form::Exception_parent::what() const throw()
{
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form cannot have a grade > 150!\n");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form cannot have get a grade < 1!\n");
}

void Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() > this->getGradeSign())
		throw(Form::GradeTooLowException());
	this->_signed = true;
}

std::ostream & operator<<(std::ostream &o, Form const &src)
{
	o << "Form: " << src.getName() << " is " << src.getSign() << " signed with a grade need to sign: " << src.getGradeSign() << " , a grade needed to execute: " << src.getGradeSign();
	return (o);
}