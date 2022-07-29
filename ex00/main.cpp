/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:32 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/08 14:20:20 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int		main() {

	int		nbElements  = 4;
	int		dataValue = 50;
	int		associatedKey = 'b';
	std::vector<int>		bigArray(nbElements, 200);
	std::list<int>			bigList(nbElements, 50);
	std::map<char, int>		bigAssociation;
	

	bigAssociation['a'] = 100;
	bigAssociation['b'] = 100;
	bigAssociation['c'] = 100;
	bigAssociation['d'] = 100;

	std::cout << "Test on vector container : suppose to catch an exception " << std::endl;
	try {
	easyfind(bigArray, dataValue);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test on list container : suppose to work without throwing " << std::endl;
	try {
	easyfind<std::list<int> >(bigList, dataValue);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////MAP CONTAINER////////////////////////////////////////////
	//

	std::cout << "Test on map container : suppose to work without throwing " << std::endl;
	try {
	easyfind(bigAssociation, associatedKey);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	associatedKey = 'w';

	std::cout << "Test on map container : suppose to catch an exception " << std::endl;
	try {
	easyfind(bigAssociation, associatedKey);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
