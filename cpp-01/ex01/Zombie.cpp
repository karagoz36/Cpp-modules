/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:01:34 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 15:14:15 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << name << "is destroyed." << std::endl;
}

void Zombie::setName(std::string zombieName) {
	name = zombieName;
}

void Zombie::announce () const {
	std::cout << name << "BraiiiiiiinnnzzzZ..." << std::endl;
}
