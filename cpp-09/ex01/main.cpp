/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:39:07 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/13 17:41:30 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2)
		return (std::cerr << "Error: wrong number of arguments." << std::endl, 1);

	RPN rpn;
	try {
		int result = rpn.evaluate(argv[1]);
		std::cout << "Result: " << result << std::endl;
	} catch (const std::exception& e) {
		return (std::cerr << e.what() << std::endl, 1);
	}
	return (0);
}
