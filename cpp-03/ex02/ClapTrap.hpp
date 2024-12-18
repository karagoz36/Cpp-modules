/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:49:34 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 17:04:34 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPT_TRAP_HPP
# define CLAPT_TRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);

	void takeDamage(unsigned int amout);
	void beRepaired(unsigned int amount);
};

#endif
