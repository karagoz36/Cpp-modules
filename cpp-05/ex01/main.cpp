/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:59:40 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 18:25:26 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 100);

		Form formA("FormA", 75, 50);
		Form formB("FormB", 120, 100);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 100);

		Form formA("FormA", 75, 50);
		Form formB("FormB", 120, 100);

		bob.signForm(formA);
		alice.signForm(formA);

		bob.signForm(formB);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form highForm("HighForm", 0, 50);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << " (HighForm creation failed)" << std::endl;
	}

	try {
		Form lowForm("LowForm", 151, 50);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << " (LowForm creation failed)" << std::endl;
	}

	return (0);
}
