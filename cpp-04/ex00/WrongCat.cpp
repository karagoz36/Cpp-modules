/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:30:53 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 11:48:26 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() /*: WrongAnimal()*/ {
	_type = "defaultWrongCat";
	std::cout << "WrongCat " << _type << " is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) /*: WrongAnimal(other)*/ {
	 _type = other._type;
	std::cout << "WrongCat " << _type << " has been copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat " << _type << " has been assigned!" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat makes a sound" << std::endl;
}
