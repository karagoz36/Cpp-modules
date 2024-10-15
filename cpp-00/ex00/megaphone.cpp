/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:03:12 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/15 15:03:14 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			std::cout << static_cast<char>(toupper(argv[i][j]));
		}
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
