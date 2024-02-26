/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/22 17:48:10 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

#include <iomanip>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	
	public:
	
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;

		class Exception_CannotOpen : public std::exception
		{
			public :
				virtual const char* what () const throw();
		};
		
};

std::ostream & operator<<(std::ostream &o, AForm const & src);

#endif