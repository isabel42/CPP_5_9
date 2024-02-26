/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:55 by itovar-n          #+#    #+#             */
/*   Updated: 2024/02/23 14:36:00 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		~ScalarConverter();

		static void convert(const std::string& argv);

	private:
		ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & src);
		ScalarConverter (ScalarConverter const & src);
		

	
};

#endif
