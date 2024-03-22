/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:39:02 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/22 15:58:50 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::list <int>	_list;
		std::vector <int> _vector;
		
	public:
		PmergeMe();
		PmergeMe(int argc, char **input);
		~PmergeMe();
		PmergeMe(PmergeMe &src);
		PmergeMe & operator=(PmergeMe &src);

		std::list <int> getList();
		std::vector <int> getVector();
		// FJList();
		// FJVector();
		
};

#endif