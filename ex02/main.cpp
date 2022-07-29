/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:54:04 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 18:49:39 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int		main() {


	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////////////Test with my own main    :////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;


	std::srand(time(NULL));

	{
		MutantStack<int, std::vector<int> >		newStackV;

		std::list<int>							newList;
		std::list<int>							diffList;

		std::cout << "Generation a Stack by copy" << std::endl;
		std::stack<int, std::vector<int> >		testCopy(newStackV);

		std::cout << "Generation of Stacks and lists" << std::endl;
		for (int i = 0 ; i < 20 ; i++) {
			int		nb = std::rand();
			newStackV.push(nb);
			newList.push_back(nb);
		}

		for (int i = 0 ; i < 20 ; i++) {
			diffList.push_back(std::rand());
		}
		std::cout << "Done." << std::endl << std::endl;


		std::cout << "Comparison between identical list and stack" << std::endl;
		MutantStack<int, std::vector<int> >::iterator	it = newStackV.begin();
		std::list<int>::iterator						itList = newList.begin();
		it = newStackV.begin();

		for ( ; it != newStackV.end() && itList != newList.end() ; it++, itList++) {
			std::cout << "------Mutantstack		" << *it << "	||	List	" << *itList << std::endl;
			if (*it != *itList) {
				std::cout << "THE TWO ITERATORS ARE DIFFERENTS" << std::endl;
				return 1;
			}
		}
		std::cout << "Done." << std::endl << std::endl;


		std::cout << "Comparison between different list and stack" << std::endl;
		std::list<int>::iterator			itDiff = diffList.begin();
		it = newStackV.begin();

		for ( ; it != newStackV.end() && itDiff != newList.end() ; it++, itDiff++) {
			std::cout << "------Mutantstack		" << *it << "	||	List	" << *itDiff << std::endl;
			if (*it != *itDiff) {
				std::cout << "THE TWO ITERATORS ARE DIFFERENTS" << std::endl;
				break;
			}
		}
	}
	std::cout << std::endl;

	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//////////////////////////////Test with subject's main :////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		return 0;
	}
}
