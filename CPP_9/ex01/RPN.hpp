/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:07:03 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/21 20:53:52 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> numbers;
		std::stack<char> sign;
		
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();
		RPN & operator=(RPN const &src);
		
		int TreatInput(std::string const & input);
		
};

#endif