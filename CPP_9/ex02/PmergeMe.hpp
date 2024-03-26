/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:39:02 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/26 14:57:52 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>

class PmergeMe
{
	private:
		std::list <std::list<int> > _list_nested;
		std::list <int>	_list;
		std::deque <int> _deque;
		
	public:
		PmergeMe();
		PmergeMe(int argc, char **input);
		~PmergeMe();
		PmergeMe(PmergeMe &src);
		PmergeMe & operator=(PmergeMe &src);

		void printNestedList();
		void list_cut(std::list <int> simple_list);
		std::list<int> getSimpleList();

		
};

#endif