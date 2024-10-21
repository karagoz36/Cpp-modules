/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/21 13:34:06 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {

private:
	static void debug(void);
	static void info(void);
	static void warning(void);
	static void error(void);
	Harl();
	~Harl();

public:
	static void complain(std::string level);
};

#endif
