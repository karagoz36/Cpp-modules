/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:27:43 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 20:32:34 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "defaultCat";
	std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) {
	 _type = other._type;
	std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Cat " << _type << " has been assigned!" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat makes a sound" << std::endl;
}
