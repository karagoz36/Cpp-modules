/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:50:50 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/08 15:28:08 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <iterator>

class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return ("Value not found in container");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw NotFoundException();
	}
	return (it);
}
//T::iterator -> std::vector<int>::iterator, std::list<int>::
