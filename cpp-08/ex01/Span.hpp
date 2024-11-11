/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/11 18:37:47 by tkaragoz         ###   ########.fr       */
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
	Span() : _capacity(0) {}
	Span(unsigned int N) : _capacity(N) {}
	Span(const Span& other) : _capacity(other._capacity), _numbers(other._numbers) {}
	Span & operator=(const Span& other) {
		if (this != &other) {
			_capacity = other._capacity;
			_numbers = other._numbers;
		}
		return (*this);
	}
	~Span() {}

	void addNumber(int number) {
		if (_numbers.size() >= _capacity)
			throw std::out_of_range("Capacity exceeded");
		_numbers.push_back(number);
	}

	//template <typename InputIterator>

	void addNumbers(/*InputIterator*/ std::vector<int>::iterator begin, /*InputIterator*/ std::vector<int>::iterator end) {
		if (std::distance(begin, end) + _numbers.size() > _capacity)
			throw std::out_of_range("Capacity exceeded");
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan() const {
		if (_numbers.size() < 2)
			throw std::logic_error("Not enough elements to find a span");

		std::vector<int> sorted = _numbers;
		std::sort(sorted.begin(), sorted.end());

		int shortest = sorted[1] - sorted[0];
		for(size_t i = 1; i < sorted.size() - 1; i++) {
			int span = sorted[i + 1] - sorted[i];
			if (span < shortest)
				shortest = span;
		}
		return (shortest);
	}

	int longestSpan() const {
		if (_numbers.size() < 2)
			throw std::logic_error("Not enough elements to find a span");

		int	min = *std::min_element(_numbers.begin(), _numbers.end());
		int	max = *std::max_element(_numbers.begin(), _numbers.end());
		return (max - min);
	}

};
