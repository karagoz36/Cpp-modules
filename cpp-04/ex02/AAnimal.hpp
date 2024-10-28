/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:02:35 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 20:02:37 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal {
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
