/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:52:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 16:28:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "=== ClapTrap Testing ===" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("Target2");
	clap.takeDamage(15);
	clap.beRepaired(10);
	std::cout << std::endl;

	// ScavTrap sınıfını test edelim
	std::cout << "=== ScavTrap Testing ===" << std::endl;
	ScavTrap scav("Guardian");

	scav.attack("Bandit");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();
	scav.attack("Enemy");
	scav.takeDamage(100); // Sağlığı sıfırlayalım
	scav.beRepaired(5);   // Enerji puanları yokken onarım denemesi
	std::cout << std::endl;

	return (0);
}
