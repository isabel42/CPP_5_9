/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:37 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/29 17:32:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): grade (150), name ("Default")
{
	std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(int tent_grade) : name ("Default")
{
	if (tent_grade < 1)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (tent_grade > 150)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
	else
		std::cout << "Constructor based on grade called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string tent_name) : name (tent_name)
{
	std::cout << "Constructor based on name called." << std::endl;
	
}

Bureaucrat::Bureaucrat(int tent_grade, std::string tent_name) : grade(tent_grade), name(tent_name)
{
	if (tent_grade < 1)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (tent_grade > 150)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
	else
		std::cout << "Constructor based on grade and name called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Constructor based con ref called." << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Surcharge operator = called." << std::endl;
	this->grade = src.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return(this->name);
}

int Bureaucrat::getGrade() const
{
	return(this->grade);
}

void Bureaucrat::IncrementeGrade()
{
	if (this->getGrade() <= 1)
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		std::cout << "Incrementing by -1 bureaucrate " << *this;
		this->grade = this->getGrade() - 1;
	}
}

void Bureaucrat::DecrementeGrade()
{
	if (this->getGrade() >= 150)
		throw(Bureaucrat::GradeTooHighException());
	else
	{
		std::cout << "Decrementing by +1 bureaucrat " << *this;
		this->grade = this->getGrade() + 1;
	}
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}

// ---------------------- BureaucratException Functions -----------------------

const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade < 1!\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade > 150!\n");
}