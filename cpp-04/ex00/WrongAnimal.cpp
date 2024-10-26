/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:18 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/26 16:17:58 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default") {
	std::cout << "WrongAnimal " << _type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type) {
	std::cout << "WrongAnimal " << _type << " has been copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other){
		_type = other._type;
	}
	std::cout << "WrongAnimal " << _type << " has been assigned!" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (_type);
}


