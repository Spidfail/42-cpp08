/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:26 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 18:21:13 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>


class STLNotFindException : public std::exception {
	private:
		const char	*_errStr;
		STLNotFindException		&operator=(STLNotFindException const &) {
			return *this;
		}
		STLNotFindException();

	public:
		STLNotFindException(STLNotFindException const &) {
		}
		STLNotFindException(const char *errStr) : _errStr(errStr) {
		}
		virtual	~STLNotFindException() throw() {}
		virtual const char *what() const throw() {
			return (_errStr);
		}
};


template <typename C>
void	easyfind(C &data, int &number) {

	typename C::const_iterator	it;

	it = std::find(data.begin(), data.end(), number);
	if (it == data.end())
		throw (STLNotFindException("Number of type <int> not found"));
}

template <>
inline void	easyfind(std::map<char, int> &data, int &number) {

	std::map<char, int>::const_iterator	it;

	it = data.find(static_cast<char>(number)); 
	if (it == data.end())
		throw (STLNotFindException("Key of type <char> not found"));
}

#endif
