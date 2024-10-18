/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:21:14 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 19:02:40 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string startType) : _type(startType) {}

const std::string& Weapon::getType(void) const {
	return (_type);
};

void Weapon::setType(std::string newType){
	_type = newType;
}


