/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:12:57 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 18:58:22 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <cstddef>

template <typename T, class Ct = std::deque<T> >
class MutantStack : public std::stack<T, Ct> {
	public:
		MutantStack() : std::stack<T, Ct>() { }
		virtual ~MutantStack() { }
		MutantStack(MutantStack const &target) : std::stack<T, Ct>() {
			*this = target;
		}
		MutantStack		&operator=(MutantStack const &target) {
			this->c = target->c;
			return *this;
		}

		// typedef typename std::stack<T, Ct>::container_type::iterator iterator;
		//// Also, this can work :
		typedef typename MutantStack::container_type::iterator iterator;

		iterator	begin() {
			return this->c.begin();
		}
		iterator	end() {
			return this->c.end();
		}
};

/////////////////////////////////////////////////////////////////////////////////
//////////////////////////Code to implement an iterator//////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//
	// class iterator : std::list<T>::iterator {
//
		// private:
			// T	*pointer;
//
		// public:
			// iterator() : pointer(MutantStack::iterator::top()) { }
			// iterator(iterator const &target) : pointer(target.top()) { }
			// ~iterator() { }
			// iterator	&operator=(iterator const &) { }
//
			// T	*begin() { return pointer; }
			// T	*end() { return pointer[MutantStack::top()]; }
			// T	*rbegin() { return this->end(); }
			// T	*rend() { return this->begin(); }
//
			// bool	operator==(T const &targetIt) {
				// if (*this->pointer == *targetIt)
					// return true;
				// return false;
			// }
			// bool	operator!=(T const &targetIt) {
				// if (*this->pointer != *targetIt)
					// return true;
				// return false;
			// }
//
			// T		operator*(void) { return *this->pointer; }
			// T		operator->(void) { return *this->pointer; }
//
			// T		*operator++() {  }
			// T		*operator++(int) { }
//
			// T		*operator--() { }
			// T		*operator--(int) { }
	// };

#endif
