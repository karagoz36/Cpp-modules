/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:01 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/21 13:25:36 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main(int argc, char **argv) {

	if (argc != 2 || !argv || !argv[1]) {
		std::cout << "INCORRECT INTPUT" << std::endl;
		return (1);
	}
	Harl::complain(argv[1]);
	return (0);
}
