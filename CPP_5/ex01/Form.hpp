/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/21 17:50:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

#include "Bureaucrat.hpp"

class Form
{
	private :
		std::string const	_name;
		bool				_sign;
		int const			_grade_sign;
		int const			_grade_exec;
	
	public:
	
		class Exeption_parent : public std::exception
		{
			public :
				virtual const char* what () const throw();
		};
		
		class GradeTooHighException : public Form::Exeption_parent
		{
			public :
				virtual const char* what () const throw();
		};
		
		class GradeTooLowException : public Form::Exeption_parent
		{
			public :
				virtual const char* what () const throw();
		};
		
		Form();
		~Form();
		Form(Form & src);
		Form & operator=(Form & src);

		std::string getName() const;
		bool getSign();
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &src);
		
};

std::ostream & operator<<(std::ostream &o, Form const & src);

#endif