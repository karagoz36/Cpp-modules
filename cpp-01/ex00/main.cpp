/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:09:04 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 14:46:48 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {

	Zombie* heapZombie = newZombie("HeapZombie");

	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie");

	return (0);
}
