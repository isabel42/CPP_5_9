/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:56 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:28 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::string joker;
    std::list <int> list_simple;
	for (int i = 1; i < argc ; i++) 
	{
		joker = argv[i];
		for (std::size_t j = 0; j < joker.size(); j++)
		{
			if (!isdigit(joker[j]))
				throw(std::logic_error("Program only accepts numbers."));
		}
		if (joker.compare("2147483647") > 0 && joker.size() >= 10)
			throw(std::logic_error("Number is out of int scope."));
		this->_deque.push_back(std::atoi(argv[i]));
		this->_list.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::list_cut(std::list <int> list_simple)
{
    std::list <int> list1;
    std::list <int> list2;
    std::list<int>::iterator it = list_simple.begin();
    if (list_simple.size() == 1)
    {
        this->_list_nested.push_back(list_simple);
        return ;
    }
    if (list_simple.size() % 2 == 1)
    {
        list1.push_back(*it);
        it++;
        list_simple.pop_front();
        this->_list_nested.push_back(list1);
    }
	if (list_simple.size() < 3)
    {
        list2.push_back(*it);
        list_simple.pop_front();
        it++;
        list2.push_back(*it);
        list_simple.pop_front();
        it++;
        list2.sort();
        this->_list_nested.push_back(list2);
    }
    else
    {
        std::list<int> h1;
        std::list<int> h2;
        for(std::size_t i = 0; i < list_simple.size() / 2; i++)
        {
            h1.push_back(*it);
            it++;
        }
        for(std::size_t i = 0; i < list_simple.size() / 2; i++)
        {
            h2.push_back(*it);
            it++;
        }
        this->list_cut(h1);
        this->list_cut(h2);
    }
 }


PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe (PmergeMe &src)
{
	*this = src;
}


PmergeMe & PmergeMe::operator=(PmergeMe &src)
{

	this->_list_nested = src._list_nested;
	this->_deque = src._deque;
	return (*this);
}

void PmergeMe::printNestedList() 
{ 
    std::cout << "[\n"; 
 
    // nested_list`s iterator(same type as nested_list) 
    // to iterate the nested_list 
    std::list<std::list<int> >::iterator nested_list_itr; 
 
    // Print the nested_list 
    for (nested_list_itr = this->_list_nested.begin(); 
        nested_list_itr != this->_list_nested.end(); 
        ++nested_list_itr) { 
 
        std::cout << " ["; 
 
        // normal_list`s iterator(same type as temp_list) 
        // to iterate the normal_list 
        std::list<int>::iterator single_list_itr; 
 
        // pointer of each list one by one in nested list 
        // as loop goes on 
        std::list<int>& single_list_pointer = *nested_list_itr; 
 
        for (single_list_itr = single_list_pointer.begin(); 
            single_list_itr != single_list_pointer.end(); 
            single_list_itr++) { 
            std::cout << " " << *single_list_itr << " "; 
        } 
        std::cout << "]\n"; 
    } 
    std::cout << "]\n"; 
} 

std::list <int> PmergeMe::getSimpleList()
{
    return(this->_list);
}

void PmergeMe::Merge()
{
    std::list <int> sol;
    std::list<std::list<int> >::iterator nested_list_itr;
    for (nested_list_itr = this->_list_nested.begin(); 
        nested_list_itr != this->_list_nested.end(); 
        ++nested_list_itr) 
        {
            if (nested_list_itr.size() == 1)
                continue;
            if(nested_list_itr != _list_nested.end() && 
                (nested_list_itr + 1).size() == nested_list_itr.size())
            
        }
    
}