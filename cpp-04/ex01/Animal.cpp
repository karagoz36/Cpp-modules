/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:18 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 20:08:51 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default") {
	std::cout << "Animal " << _type << " is created" << std::endl;
}

Animal::Animal(const Animal& other): _type(other._type) {
	std::cout << "Animal " << _type << " has been copied" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other){
		_type = other._type;
	}
	std::cout << "Animal " << _type << " has been assigned!" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal is destroyed" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}


