/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/03 17:03:42 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern & operator=(Intern const & src);
		Intern (Intern const & src);

		class Exception_FormNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm * makeForm(std::string form_name, std::string form_target);

	
};

#endif
