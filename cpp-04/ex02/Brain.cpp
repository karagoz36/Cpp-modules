/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 17:28:20 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Brain copied" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	//std::cout << "Brain assigned" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

std::string Brain::getIdea(int index) const {
	return ((index >= 0 && index < 100) ? ideas[index] : "Index is between 0 and 99");
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
	std::cout << "Idea " << index << " is created: " << idea << std::endl;
}
