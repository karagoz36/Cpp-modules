/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:24:24 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/31 15:56:00 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("defaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw NotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (outfile.is_open()) {
		outfile << "       _-_\n";
		outfile << "    /~~   ~~\\\n";
		outfile << " /~~         ~~\\\n";
		outfile << "{               }\n";
		outfile << " \\  _-     -_  /\n";
		outfile << "   ~  \\\\ //  ~\n";
		outfile << "_- -   | | _- _\n";
		outfile << "  _ -  | |   -_\n";
		outfile << "       | |\n\n\n";
		outfile << "       _-_\n";
		outfile << "    /~~   ~~\\\n";
		outfile << " /~~         ~~\\\n";
		outfile << "{               }\n";
		outfile << " \\  _-     -_  /\n";
		outfile << "   ~  \\\\ //  ~\n";
		outfile << "_- -   | | _- _\n";
		outfile << "  _ -  | |   -_\n";
		outfile << "       | |\n";
		outfile.close();
	}

}
