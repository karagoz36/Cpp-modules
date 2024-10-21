/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:30:30 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/21 19:32:31 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor callsed" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor calls"
}
