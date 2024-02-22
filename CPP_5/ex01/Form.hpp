/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 14:54:34 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const	_name;
		bool				_signed;
		int const			_grade_sign;
		int const			_grade_exec;
	
	public:
	
		class Exception_parent : public std::exception
		{
			public :
				virtual const char* what () const throw();
		};
		
		class GradeTooHighException : public Form::Exception_parent
		{
			public :
				virtual const char* what () const throw();
		};
		
		class GradeTooLowException : public Form::Exception_parent
		{
			public :
				virtual const char* what () const throw();
		};
		
		Form();
		Form(std::string name, int _grade_sign, int _grade_exec);
		~Form();
		Form(Form & src);
		Form & operator=(Form & src);

		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &src);
		
};

std::ostream & operator<<(std::ostream &o, Form const & src);

#endif