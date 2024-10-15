/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:58:13 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/15 21:38:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setContactDetails(const std::string& fname,
									const std::string& lname,
									const std::string& nick,
									const std::string& phone,
									const std::string& secret) {
		first_name = fname;
		last_name = lname;
		nickname = nick;
		phone_number = phone;
		darkest_secret = secret;
}

std::string	Contact::getFirstName() const {return (first_name); }
std::string	Contact::getLastName() const {return (last_name); }
std::string	Contact::getNickName() const {return (nickname); }
std::string	Contact::getPhoneNumber() const {return (phone_number); }
std::string	Contact::getDarkestSecret() const {return (darkest_secret); }

void	Contact::displayContact() const {
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
