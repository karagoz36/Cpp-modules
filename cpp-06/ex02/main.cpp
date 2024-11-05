/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:20:47 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/05 18:58:00 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "TypeIdentifier.hpp"
#include "Generator.hpp"
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* randomBase = generate();
	std::cout << "Using pointer:" << std::endl;
	identify(randomBase);
	std::cout << "Using reference:" << std::endl;
	identify(*randomBase);

	delete (randomBase);

	return (0);
}
