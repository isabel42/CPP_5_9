/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/06 14:45:58 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const name; 
		int grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);
		std::ostream & operator<<(Bureaucrat const & src);
		Bureaucrat (Bureaucrat const & src);
		
		std::string getName() const;
		int getGrade()const;
	
};

#endif
