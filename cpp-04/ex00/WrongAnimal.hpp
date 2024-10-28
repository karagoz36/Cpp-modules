/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:36:15 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 11:36:44 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
	std::string _type;

public:
	WrongAnimal();                                // Default constructor
	WrongAnimal(const WrongAnimal &other);        // Copy constructor
	WrongAnimal &operator=(const WrongAnimal &other); // Copy assignment operator
	virtual ~WrongAnimal();                       // Destructor

	void makeSound() const;                       // Non-virtual, no polymorphism
	std::string getType() const;
};

#endif // WRONGANIMAL_HPP
