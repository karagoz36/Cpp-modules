/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:21:50 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/07 16:26:25 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void printElement(T&  t) {
	std::cout << t << " ";
}

void doubleValue(int& x) {
	x *= 2;
}

void toUpperCase(char& c) {
	if (c >= 'a' && c <= 'z') {
		c -= ('a' - 'A');
	}
}

void increment(float& f) {
	f += 1.0f;
}
