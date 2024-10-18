/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:59:12 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/18 15:01:26 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

private:
	std::string name;

public:
	Zombie();
	~Zombie();
	void setName(std::string zombieName);
	void announce(void) const;
};

#endif
