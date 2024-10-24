/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:52:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/24 18:18:31 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap robot("Robocop");

	robot.attack("Bandit");
	robot.takeDamage(5);
	robot.beRepaired(3);
	robot.attack("Enemy");
	robot.takeDamage(10);
	robot.beRepaired(5);

	return (0);
}
