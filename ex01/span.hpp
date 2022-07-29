/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:25:44 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/09 14:25:03 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class Span {

	private:
		Span();
		std::vector<int>		_array;
		unsigned int			_sizeArray;

	public:
		Span(Span const &);
		Span(unsigned int const &sizeArray);
		Span	&operator=(Span const &);
		~Span();

	////////////////////////////////////////////////////////////////////////
	
		std::vector<int> const	&getArray(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addNumber(std::vector<int> const &newNb);
		void	addNumber(int const newNb);


	///////////////////////////////////////////////////////////////////////////////

		class ArrayFullException : public std::exception {
			private:
				ArrayFullException();
				const char *_rtnErr;
			public:
				ArrayFullException(const char *);
				virtual ~ArrayFullException() throw();
				virtual const char *what() const throw();
		};

		class ArrayTooShortException : public std::exception {
			private:
				ArrayTooShortException();
				const char *_rtnErr;
			public:
				ArrayTooShortException(const char *);
				virtual ~ArrayTooShortException() throw();
				virtual const char *what() const throw();
		};

};

#endif
