/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:53:45 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/31 18:42:49 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);

	// Create a valid form and execute it
	AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form1) {
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}

	// Attempt to create an invalid form
	try {
		AForm* form2 = someRandomIntern.makeForm("invalid form name", "Unknown");
		delete form2;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
