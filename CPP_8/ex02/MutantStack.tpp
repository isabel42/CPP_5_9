/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:29:12 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/14 15:39:57 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename MutantStack<T>::iteratori MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iteratori MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iteratori MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iteratori MutantStack<T>::end() const
{
	return this->c.end();
}