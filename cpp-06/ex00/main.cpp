/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:44:34 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/04 15:51:24 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./convert <numbers>" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}
