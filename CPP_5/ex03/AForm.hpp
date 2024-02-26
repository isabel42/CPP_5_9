/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 16:28:31 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		
		class GradeTooHighException : public AForm::Exception_parent
		{
			public :
				const char* what () const throw();
		};
		
		class GradeTooLowException : public AForm::Exception_parent
		{
			public :
				const char* what () const throw();
		};
		
		class UnsignedFormException : public AForm::Exception_parent
		{
			public :
				const char* what () const throw();
		};
		
		AForm();
		AForm(std::string name, int _grade_sign, int _grade_exec);
		virtual ~AForm();
		AForm(AForm & src);
		AForm & operator=(AForm & src);

		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &src);

		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExec(Bureaucrat const &src) const;
		
};

std::ostream & operator<<(std::ostream &o, AForm const & src);

#endif