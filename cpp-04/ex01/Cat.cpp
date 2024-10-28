/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:27:43 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 17:18:06 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : /*Animal()*/ brain(new Brain) {
	_type = "defaultCat";
	std::cout << "Cat " << _type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : /*Animal(other)*/ brain(new Brain(*other.brain)) {
	 _type = other._type;
	std::cout << "Cat " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other){
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat " << _type << " has been assigned!" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat is destroyed" << std::endl;
	delete (brain);
}

void Cat::makeSound() const {
	std::cout << "Cat makes a sound" << std::endl;
}

Brain *Cat::getBrain() const {
	return (brain);
}
