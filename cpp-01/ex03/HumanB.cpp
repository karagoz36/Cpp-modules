/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:13:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 19:28:28 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : _name(newName), _weapon(NULL) {}

void HumanB::attack() const {
	if (_weapon) {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	} else {
		std::cout << _name << " has no weapon to attack with!" << std::endl;
	}
}

void HumanB::setWeapon(Weapon& newWeapon) {
	//*(_weapon) = newWeapon.getType(); yanlis
	_weapon = &newWeapon;
}
