/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:27:56 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 17:00:44 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap" << _name << " has been created by default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap" << _name << " has been created by parameterized constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " has been assigned!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << _name << " cannot attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests high fives!" << std::endl;
}
