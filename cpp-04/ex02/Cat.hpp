/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:44:04 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 17:50:49 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat &other);
	~Cat();

	void makeSound() const;
	Brain *getBrain() const;
};

#endif
