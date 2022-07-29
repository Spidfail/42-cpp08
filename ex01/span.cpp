/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:25:41 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 14:24:57 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _sizeArray(0) {
}

Span::Span(Span const &target) : _array(target._array), _sizeArray(target._sizeArray) {
}

Span::Span(unsigned int const &sizeArray) : _sizeArray(sizeArray) {
}

Span::~Span() {}

///////////////////////////////////////////////////////////////////////////////
//

Span	&Span::operator=(Span const &target) {
	this->_array.clear();
	_array.insert(_array.begin(), target._array.begin(), target._array.end());
	this->_sizeArray = target._sizeArray;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////
//

std::vector<int> const	&Span::getArray(void) {

	return this->_array;
}

void	Span::addNumber(std::vector<int> const &newNb) {

	if (_array.size() < _sizeArray && newNb.size() + _array.size() <= _sizeArray) {
		_array.insert(_array.begin(), newNb.begin(), newNb.end());
	}
	else
		throw(ArrayFullException("  /!\\ The array is full of int"));
}

void	Span::addNumber(int const newNb) {

	if (_array.size() < _sizeArray) {
		_array.push_back(newNb);
	}
	else
		throw(ArrayFullException("  /!\\ The array is full of int"));
}

int		Span::shortestSpan() {

	if (this->_array.size() < 2)
		throw(ArrayTooShortException("  /!\\ The array has less than 2 elements."));

	std::vector<int>	_sortArray(_array);
	std::sort(_sortArray.begin(), _sortArray.end());

	std::vector<int>::iterator	it = _sortArray.begin();
	int		_rtn = INT_MAX;

	for (; (it + 1) != _sortArray.end() ; it++ ) {
		if (*(it + 1) - *it < _rtn) {
			_rtn = *(it + 1) - *it;
		}
	}

	return _rtn;
}

int		Span::longestSpan() {

	if (this->_array.size() < 2)
		throw(ArrayTooShortException("  /!\\ The array has less than 2 elements."));

	unsigned int	maxNb = *std::max_element(this->_array.begin(), this->_array.end());
	unsigned int	minNb = *std::min_element(this->_array.begin(), this->_array.end());
	return maxNb - minNb;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//

Span::ArrayFullException::ArrayFullException(const char *strError) : _rtnErr(strError) {}


const char		*Span::ArrayFullException::what() const throw() {
	return _rtnErr;
}

Span::ArrayFullException::~ArrayFullException() throw() {}

///////////////////////////////////////////////////////////////////////////////
//

Span::ArrayTooShortException::ArrayTooShortException(const char *strError) : _rtnErr(strError) {}


const char		*Span::ArrayTooShortException::what() const throw() {
	return _rtnErr;
}

Span::ArrayTooShortException::~ArrayTooShortException() throw() {}

