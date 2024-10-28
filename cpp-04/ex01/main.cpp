/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:59:39 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 19:59:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* animals[4];

	// Creating half dogs and half cats
	animals[0] = new Dog();
	std::cout << std::endl;
	animals[1] = new Dog();
	std::cout << std::endl;
	animals[2] = new Cat();
	std::cout << std::endl;
	animals[3] = new Cat();
	std::cout << std::endl;

	// Setting and checking ideas
	Dog *dog1 = new Dog();
	std::cout << std::endl;
	dog1->getBrain()->setIdea(0, "Chase the mailman!");
	std::cout << std::endl;

	Dog dog2(*dog1);
	std::cout << std::endl;

	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	{
	Dog dog3;
	dog3.getBrain()->setIdea(0, "Another idea");
	std::cout << "Dog3 Brain Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;
	dog3 = dog2;
	std::cout << "Dog3 Brain Idea[0]: " << dog3.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;


	// Dog dog2 = *dog1;  // Test deep copy
	// std::cout << std::endl;

	std::cout << "Dog1 Brain Idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "Dog2 Brain Idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Clean up
	for (int i = 0; i < 4; ++i) {
		delete animals[i];
		std::cout << std::endl;
	}
	delete dog1;
	std::cout << std::endl;

	return (0);
}
