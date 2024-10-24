/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:18:03 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/24 14:14:53 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const { return (_fixedPointValue > other._fixedPointValue); }
bool Fixed::operator<(const Fixed& other) const {return (_fixedPointValue < other._fixedPointValue); }
bool Fixed::operator>=(const Fixed& other) const {return (_fixedPointValue >= other._fixedPointValue); }
bool Fixed::operator<=(const Fixed& other) const {return (_fixedPointValue <= other._fixedPointValue); }
bool Fixed::operator==(const Fixed& other) const {return (_fixedPointValue == other._fixedPointValue); }
bool Fixed::operator!=(const Fixed& other) const {return (_fixedPointValue != other._fixedPointValue); }

Fixed Fixed::operator+(const Fixed& other) const {return (Fixed(this->toFloat() + other.toFloat()));}
Fixed Fixed::operator-(const Fixed& other) const {return (Fixed(this->toFloat() - other.toFloat()));}
Fixed Fixed::operator*(const Fixed& other) const {return (Fixed(this->toFloat() * other.toFloat()));}
Fixed Fixed::operator/(const Fixed& other) const {return (Fixed(this->toFloat() / other.toFloat()));}

Fixed& Fixed::operator++(){ _fixedPointValue++; return (*this); }
Fixed Fixed::operator++(int) { Fixed tmp(*this); _fixedPointValue++; return (tmp); }
Fixed& Fixed::operator--(){ _fixedPointValue--; return (*this); }
Fixed Fixed::operator--(int) { Fixed tmp(*this); _fixedPointValue--; return (tmp); }

int Fixed::getRawBits(void) const { return (_fixedPointValue); }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float Fixed::toFloat(void) const { return ((float)_fixedPointValue / (1 << _fractionalBits)); }
int Fixed::toInt(void) const {return (_fixedPointValue >> _fractionalBits);}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return ((a < b) ? a : b); }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return ((a < b) ? a : b); }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return ((a > b) ? a : b); }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {return ((a > b) ? a : b); }

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}
