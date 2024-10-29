/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:59:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/29 11:58:54 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	//const AAnimal a;
	//AAnimal* animal = new AAnimal();
	//Abstract class AAnimal cannot be instantiated.

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << " ";
	dog->makeSound();

	std::cout << cat->getType() << " ";
	cat->makeSound();

	delete (dog);
	delete (cat);

	return (0);
}
