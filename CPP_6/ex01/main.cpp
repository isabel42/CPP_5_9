/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:06 by itovar-n          #+#    #+#             */
/*   Updated: 2024/03/04 14:56:59 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* data;
	uintptr_t rawData;
	Data* retData;

	data = new Data;

	std::cout << "Data             : " << data << std::endl;
	
	rawData = Serializer::serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	
	retData = Serializer::deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	// delete data;

	return 0;
}