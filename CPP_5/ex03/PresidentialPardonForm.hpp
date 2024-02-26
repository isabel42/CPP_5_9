/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:28 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 10:35:04 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iomanip>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm : public AForm
{
	private :
		std::string _target;
	
	public:
	
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
		
};

std::ostream & operator<<(std::ostream &o, AForm const & src);

#endif