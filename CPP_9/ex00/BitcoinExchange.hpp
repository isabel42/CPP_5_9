/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:58:14 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/21 16:24:55 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data_;
		BitcoinExchange();
	
	public:
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange & operator=(const BitcoinExchange &src);
		
		BitcoinExchange(const std::string &file);
		bool DateOk(const std::string &date);
		bool ValueOk(const double &value);
		void GetOutput(const std::string &file);
		
};

#endif