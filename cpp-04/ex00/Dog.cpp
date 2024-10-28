/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:17:01 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 11:49:35 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() /*: Animal()*/ {
	_type = "defaultDog";
	std::cout << "Dog " << _type << " is created" << std::endl;
}

Dog::Dog(const Dog& other) /*: Animal(other)*/ {
	 _type = other._type;
	std::cout << "Dog " << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Dog " << _type << " has been assigned!" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog makes a sound" << std::endl;
}
