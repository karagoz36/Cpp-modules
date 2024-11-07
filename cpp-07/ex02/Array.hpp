/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:48:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/07 17:35:49 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
	T*				elements;
	unsigned int	len;

public:
	Array() : elements(NULL), len(0) {}
	Array(unsigned int n) : elements(new T[n]()), len(n) {}
	Array(const Array& other) : elements(new T[other.len]), len(other.len) {
		for (unsigned int i = 0; i < len; i++) {
			elements[i] = other.elements[i];
		}
	}
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] elements;
			len = other.len;
			elements = new T[len];
			for (unsigned int i = 0; i < len; i++) {
				elements[i] = other.elements[i];
			}
		}
		return (*this);
	}
	~Array() {
		delete[] elements;
	}
	unsigned int size() const {
		return (len);
	}
	T& operator[](unsigned int index) {
		if (index >= len) {
			throw std::out_of_range("Array index out of bounds");
		}
		return (elements[index]);
	}
	const T& operator[](unsigned int index) const {
		if (index >= len) {
			throw std::out_of_range("Array index out of bounds");
		}
		return (elements[index]);
	}
};
