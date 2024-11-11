/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/11 22:36:38 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

class Span {
private:
	unsigned int		_capacity;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span & operator=(const Span& other);
	~Span();

	void addNumber(int number);
	//template <typename T>
	void addNumbers(/*T*/ std::vector<int>::iterator begin, /*T*/ std::vector<int>::iterator end);

	int shortestSpan() const;
	int longestSpan() const;
};
