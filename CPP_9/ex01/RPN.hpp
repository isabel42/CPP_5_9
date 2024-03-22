/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:07:03 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/22 14:16:13 by itovar-n         ###   ########.fr       */
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
		
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();
		RPN & operator=(RPN const &src);
		
		void TreatInput(std::string const & input);
		void ResolveStack(const char c);
		int getTop();
		void add();
		void subs();
		void mult();
		void div();
		
};

#endif