/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:32:40 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/15 21:57:38 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_count(0), oldest_contact(0) {}

void PhoneBook::addContact(const Contact& new_contact) {
	if (current_count < 8) {
		contacts[current_count++] = new_contact;
	} else {
		contacts[oldest_contact] = new_contact;
		oldest_contact = (oldest_contact + 1) % 8;
	}
}

void PhoneBook::displayContacts() const {
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < current_count; i++) {
		std::cout	<< std::setw(10) << (i + 1) << "|"
					<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::displaySpecificContact(int index) const {
	if (index < 1 || index > current_count) {
		std::cout	<< "Invalid index!" << std::endl;
	} else {
		contacts[index - 1].displayContact();
	}
}

std::string	PhoneBook::truncate(const std::string& str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
