/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:56 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/28 09:30:01 by itovar-n         ###   ########.fr       */
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

std::list <int> PmergeMe::getSimpleList()
{
    return(this->_list);
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

void PmergeMe::MergeList()
{
    std::list<std::list<int> >::iterator nested_list_itr;
	while (this->_list_nested.size() > 1)
	{
		for (nested_list_itr = this->_list_nested.begin(); 
			nested_list_itr != this->_list_nested.end(); 
			++nested_list_itr) 
		{
			std::list<int>& single_list_pointer = *nested_list_itr;
			std::list<std::list<int> >::iterator nested_list_itr_prev = std::prev(nested_list_itr);
			std::list<int>& single_list_pointer_prev = *(nested_list_itr_prev);
			std::list<std::list<int> >::iterator nested_list_itr_next = std::next(nested_list_itr);
			std::list<int>& single_list_pointer_next = *(nested_list_itr_next);
			if (single_list_pointer.size() == 1)
				continue;
			else
			{
				if (single_list_pointer.size() == single_list_pointer_next.size())
				{
					if (single_list_pointer_prev.size() == 1 && (std::next(nested_list_itr_next) == this->_list_nested.end() || std::next(nested_list_itr_next)->size() == 1))
					{
						std::cout << "Sort three: prev, this and next" << std::endl;
						std::list <int> sol = this->Consol_three(single_list_pointer, single_list_pointer_next, single_list_pointer_prev);
						this->_list_nested.erase(nested_list_itr_prev);
						this->_list_nested.insert(nested_list_itr,sol);
						++nested_list_itr;
						this->_list_nested.erase(std::prev(nested_list_itr));
						--nested_list_itr;
						this->_list_nested.erase(std::next(nested_list_itr));
						
					}
					else
					{	
						std::cout << "Sort two. This and next" << std::endl;
						std::list <int> sol = this->Consol(single_list_pointer, single_list_pointer_next);
						this->_list_nested.insert(nested_list_itr,sol);
						++nested_list_itr;
						this->_list_nested.erase(std::prev(nested_list_itr));
						--nested_list_itr;
						this->_list_nested.erase(std::next(nested_list_itr));
					}
				}
				else
				{
					std::cout << "Sort two: prev and this. " << std::endl;
					std::list <int> sol = this->Consol(single_list_pointer, single_list_pointer_prev);
					this->_list_nested.insert(nested_list_itr,sol);
					this->_list_nested.erase(nested_list_itr_prev );
					++nested_list_itr--;
					nested_list_itr_next = std::next(nested_list_itr);
					this->_list_nested.erase(nested_list_itr_next );
				}
			}
		}
	}
}

std::list <int> PmergeMe::Consol(std::list <int> first, std::list <int> second)
{
    std::list <int> sol;
	std::list<int>::iterator it1 = first.begin();
	std::list<int>::iterator it2 = second.begin();

	while(it1 != first.end() || it2 != second.end())
	{
		if (((*it1 < *it2 || it2 == second.end()) && it1 != first.end()))
		{
			sol.push_back(*it1);
			it1++;
		}
		else
		{
			sol.push_back(*it2);
			it2++;
		}
	}
	return (sol);
}


std::list <int> PmergeMe::Consol_three(std::list <int> first, std::list <int> second, std::list <int> third)
{
    std::list <int> sol;
	std::list<int>::iterator it1 = first.begin();
	std::list<int>::iterator it2 = second.begin();
	std::list<int>::iterator it3 = third.begin();

	while(it1 != first.end()|| it2 != second.end() || it3 != third.end())
	{
		if ((((*it1 <= *it2)|| it2 == second.end()) && (*it1 < *it3 || it3 == third.end())) && it1 != first.end())
		{
			sol.push_back(*it1);
			it1++;
		}
		else if ((*it2 < *it3 || it3 == third.end()) && it2 != second.end())
		{
			sol.push_back(*it2);
			it2++;
		}
		else 
		{
			sol.push_back(*it3);
			it3++;
		}
	}
	return (sol);
}