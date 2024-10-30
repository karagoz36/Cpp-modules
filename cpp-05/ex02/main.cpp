/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:59:40 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 19:06:07 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 30);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bob");
        PresidentialPardonForm pardon("Charlie");

        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        alice.signForm(robotomy);
        alice.executeForm(robotomy);

        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
