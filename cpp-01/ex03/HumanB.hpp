/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:08:49 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 19:15:02 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <string>
#include <iostream>

class HumanB {

private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB(std::string newName);
	void attack() const;
	void setWeapon(Weapon& newWeapon);
};
