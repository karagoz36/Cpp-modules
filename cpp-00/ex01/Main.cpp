/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:06:17 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/16 18:09:17 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

int main() {
	PhoneBook	phonebook;
	std::string	command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nInput closed. Exiting the program." << std::endl;
			break;
		}

		if (command == "ADD") {
			std::string fname, lname, nick, phone, secret;
			std::cout << "Enter first name: ";
			std::getline(std::cin, fname);
			std::cout << "Enter last name: ";
			std::getline(std::cin, lname);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nick);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phone);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, secret);

			if (!fname.empty() && !lname.empty() && !nick.empty() && \
				!phone.empty() && !secret.empty()) {
				Contact new_contact;
				new_contact.setContactDetails(fname, lname, nick, phone, secret);
				phonebook.addContact(new_contact);
			} else {
				std::cout << "Error: All fields must be filled." << std::endl;
			}
		} else if (command == "SEARCH") {
			phonebook.displayContacts();
			std::cout << "Enter index of contact to view: ";
			std::string input;
			std::getline(std::cin, input);
			std::stringstream ss(input);
			int index;
			if (ss >> index && ss.eof()) {
				phonebook.displaySpecificContact(index);
			} else {
				std::cout << "Invalid input! Please enter a number." << std::endl;
			}
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Unknown command." << std::endl;
		}
	}
	return (0);
}
