/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:34:58 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/13 14:13:36 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Exception_parent : public std::exception
{
	public :
		virtual const char* what () const throw();
};
		
template<typename T> 
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator i = std::find(container.begin(), container.end(), n);
	if (i == container.end())
		throw (std::out_of_range("easyfind::NotFoundException"));
	return (i);
}