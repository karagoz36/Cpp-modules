/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:18 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 20:08:51 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default") {
	std::cout << "AAnimal " << _type << " is created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): _type(other._type) {
	std::cout << "AAnimal " << _type << " has been copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
	if (this != &other){
		_type = other._type;
	}
	std::cout << "AAnimal " << _type << " has been assigned!" << std::endl;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal is destroyed" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal makes a sound" << std::endl;
}

std::string AAnimal::getType() const {
	return (_type);
}


