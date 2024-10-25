/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:12:41 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/25 17:07:52 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {

	std::cout << "=== ClapTrap Testing ===" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("Target2");
	clap.takeDamage(15);
	clap.beRepaired(10);
	std::cout << std::endl;

	//ScavTrap Testing
	std::cout << "=== ScavTrap Testing ===" << std::endl;
	ScavTrap scav("Guardian");

	scav.attack("Bandit");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();
	scav.attack("Enemy");
	scav.takeDamage(100); //Zero health
	scav.beRepaired(5); //Reparing without health
	std::cout << std::endl;

	// FragTrap testing
	std::cout << "=== FragTrap Testing ===" << std::endl;
	FragTrap frag("Hero");

	frag.attack("Villain");
	frag.takeDamage(30);
	//frag.beRepaired(20);
	frag.highFivesGuys();

	//Additional FragTrap Scenarios
	std::cout << "\n=== Additional FragTrap Scenarios ===" << std::endl;
	frag.takeDamage(80);  // Zero health
	frag.beRepaired(50);  // Reparing without health
	frag.attack("Enemy2"); // Attack without health

	// // Enerji sıfırlama testi
	// std::cout << "\n=== Energy Exhaustion Test ===" << std::endl;
	// for (int i = 0; i < 100; ++i) { // Attack without energypoints
	// 	frag.attack("Training Dummy");
	// }
	// frag.beRepaired(10); // Reparing without energypoints
	return (0);
}
