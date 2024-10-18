/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:47 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 16:19:24 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {

	int N = 5;
	Zombie* horde = zombieHorde(N, "zombieHorde");

	for (int i = 0; i < N; i++){
		horde->announce();
	}
	delete[] horde;

	return (0);
}
