/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:20:44 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iomanip>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;
	
	public:
	
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;

		class Exception_RobotomyFailed : public std::exception
		{
			public :
				virtual const char* what () const throw();
		};
		
};

std::ostream & operator<<(std::ostream &o, AForm const & src);

#endif