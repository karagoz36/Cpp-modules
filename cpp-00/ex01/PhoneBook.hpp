/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:07:17 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/16 13:01:31 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

# include "Contact.hpp"

class PhoneBook {
	private:
	Contact	contacts[8];
	int		current_count;
	int		oldest_contact;

	public:
	PhoneBook();
	void	addContact(const Contact& new_contact);
	void	displayContacts() const;
	void	displaySpecificContact(int index) const;

	private:
		std::string truncate(const std::string& str) const;
};

#endif
