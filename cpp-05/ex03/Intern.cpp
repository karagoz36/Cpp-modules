/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:59 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/31 18:41:48 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[] = {
		new	ShrubberyCreationForm(target),
		new	RobotomyRequestForm(target),
		new	PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++) {
				if (j !=i)
					delete forms[j];
			}
			return (forms[i]);
		}
	}
	std::cout << "Error: Form name not recognized." << std::endl;
	for (int i = 0; i < 3; i++)
		delete (forms[i]);
	return (NULL);
};