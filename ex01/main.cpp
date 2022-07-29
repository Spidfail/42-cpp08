/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:25:52 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 18:25:22 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int		main()
{
	std::srand(time(NULL));

	{
		Span	newSpan(5);

		std::cout << "/////////////////////////////////////////////////////////" << std::endl;
		std::cout << "//////////////////////TEST 1/////////////////////////////" << std::endl;
		std::cout << "/////Try an incremental add of number (overflow)/////////" << std::endl;
		std::cout << "/////////////////////////////////////////////////////////" << std::endl << std::endl;

		try {
		std::cout << "Add number 1 to 10 in order (manualy)" << std::endl;
			std::cout << "+0" << std::endl;
			newSpan.addNumber(0);
			std::cout << "+1" << std::endl;
			newSpan.addNumber(1);
			std::cout << "+2" << std::endl;
			newSpan.addNumber(2);
			std::cout << "+3" << std::endl;
			newSpan.addNumber(3);
			std::cout << "+4" << std::endl;
			newSpan.addNumber(4);
			std::cout << "+5" << std::endl;
			newSpan.addNumber(5);
			std::cout << "+6" << std::endl;
			newSpan.addNumber(6);
			std::cout << "+7" << std::endl;
			newSpan.addNumber(7);
			std::cout << "+8" << std::endl;
			newSpan.addNumber(8);
			std::cout << "+9" << std::endl;
			newSpan.addNumber(9);
			std::cout << "+10" << std::endl;
			newSpan.addNumber(10);
			std::cout << std::endl;

			std::cout << "Launch longestSpan :";
			std::cout << newSpan.longestSpan() << std::endl;

			std::cout << "Launch shortestSpan :";
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}


		Span	newSpan2(newSpan);
		Span	newSpan3 = newSpan;

		std::cout << "Copy constructor test printed " << std::endl;
		for (std::vector<int>::const_iterator it = newSpan2.getArray().begin() ;
				it != newSpan2.getArray().end() ;
				it++) {
			std::cout << *it << std::endl;
		}

		std::cout << "Assignation operator test printed :" << std::endl;
		for (std::vector<int>::const_iterator it = newSpan3.getArray().begin() ;
				it != newSpan3.getArray().end() ;
				it++) {
			std::cout << *it << std::endl;
		}

	}


	std::cout << "/////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////TEST 2/////////////////////////////" << std::endl;
	std::cout << "//////////Try to insert a range of number (vector)///////" << std::endl;
	std::cout << "////////////////////(overflow)///////////////////////////" << std::endl << std::endl;
	{

		Span				newSpan(5);
		std::vector<int>	goodArray;

		std::cout << "Generate number 1 to 200 in order" << std::endl;
		for (int i = 0 ; i < 200 ; i++)
			goodArray.push_back(std::rand());

		try {
			std::cout << "Launch addNumber ";
			newSpan.addNumber(goodArray);
			std::cout << std::endl;

			std::cout << "Launch longestSpan :";
			std::cout << newSpan.longestSpan() << std::endl;

			std::cout << "Launch shortestSpan :";
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}


	std::cout << "/////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////TEST 3/////////////////////////////" << std::endl;
	std::cout << "//////////Try to insert a range of number (vector)///////" << std::endl;
	std::cout << "/////////////////(suppose to work)///////////////////////" << std::endl << std::endl;
	{
		Span				newSpan(5);
		std::vector<int>	goodArray;
		
		std::cout << "Generate 4 random number in random order" << std::endl;
		for (int i = 0 ; i < 4 ; i++) {
			int		getRand = std::rand();
			std::cout << getRand << std::endl;
			goodArray.push_back(getRand);
		}


		try {
			std::cout << "Launch addNumber ";
			newSpan.addNumber(goodArray);
			std::cout << std::endl;

			std::cout << "Launch longestSpan :";
			std::cout << newSpan.longestSpan() << std::endl;

			std::cout << "Launch shortestSpan :";
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}


	std::cout << "/////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////TEST 4/////////////////////////////" << std::endl;
	std::cout << "//////////Try to insert a LARGE range of number//////////" << std::endl;
	std::cout << "/////////////////(suppose to work)///////////////////////" << std::endl << std::endl;
	{
		Span				newSpan(20000);
		std::vector<int>	goodArray;

		std::cout << "Generate 10 000 random numbers in random order" << std::endl;
		for (int i = 0 ; i < 10000 ; i++) {
			int		getRand = std::rand();
			goodArray.push_back(getRand);
		}

		try {
			std::cout << "Launch addNumber ";
			newSpan.addNumber(goodArray);
			std::cout << std::endl;

			std::cout << "Launch longestSpan :";
			std::cout << newSpan.longestSpan() << std::endl;

			std::cout << "Launch shortestSpan :";
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	std::cout << "/////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////TEST 5/////////////////////////////" << std::endl;
	std::cout << "//////////Try to insert too few numbers !////////////////" << std::endl;
	std::cout << "/////////////////(not working !)/////////////////////////" << std::endl << std::endl;

	{
		Span	newSpan(20);
		std::vector<int>	goodArray;

		std::cout << "Generate 2 random numbers in random order" << std::endl;
		for (int i = 0 ; i < 2 ; i++)
			goodArray.push_back(std::rand());

		try {
			std::cout << "Launch addNumber ";
			newSpan.addNumber(goodArray);
			std::cout << std::endl;

			std::cout << "Launch longestSpan :";
			std::cout << newSpan.longestSpan() << std::endl;

			std::cout << "Launch shortestSpan :";
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}

}
