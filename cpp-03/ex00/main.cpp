/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:52:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 16:26:11 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	// ClapTrap robot("Robocop");

	// robot.attack("Bandit");
	// robot.takeDamage(5);
	// robot.beRepaired(3);
	// robot.attack("Enemy");
	// robot.takeDamage(10);
	// robot.beRepaired(5);

	// ClapTrap testleri
	std::cout << "=== ClapTrap Testing ===" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("Target2");
	clap.takeDamage(15);
	clap.beRepaired(10);
	std::cout << std::endl;

	return (0);
}
