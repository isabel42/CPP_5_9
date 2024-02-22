/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/21 17:52:53 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	private:
		int grade;
		std::string const name; 

	public:
		Bureaucrat();
		Bureaucrat(int tent_grade);
		Bureaucrat(int tent_grade, std::string tent_name);
		Bureaucrat(std::string tent_name);
		~Bureaucrat();
		
		Bureaucrat & operator=(Bureaucrat const & src);
		Bureaucrat (Bureaucrat const & src);
		
		std::string getName() const;
		int getGrade()const;
		void IncrementeGrade();
		void DecrementeGrade();

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};


		void signForm(Form & src);
	
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &src);

#endif
