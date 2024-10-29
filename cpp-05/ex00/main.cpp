/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:59:40 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/29 18:08:50 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat validPerson("Cool Guy", 10);
		std::cout << validPerson << std::endl;
		validPerson.decrementGrade();
		std::cout << validPerson << std::endl;
		validPerson.incrementGrade();
		validPerson.incrementGrade();
		std::cout << validPerson << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat highRanker("The Lawyer", 1);
		std::cout << highRanker << std::endl;
		highRanker.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat lowRanker("Bartleby, the Scrivener", 150);
		std::cout << lowRanker << std::endl;
		lowRanker.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Test for The Narrator (200)" <<std::endl;
		Bureaucrat invalid("The Narrator", 200);
		std::cout << invalid <<std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
