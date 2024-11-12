/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:17:23 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/12 15:26:26 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
	MutantStack<T>& operator=(const MutantStack<T>& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin() {return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() {return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};
