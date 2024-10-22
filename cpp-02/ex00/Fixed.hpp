/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:20:56 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/22 14:20:28 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

2.5 << _fractionalBits
1 << 8
private:
	int					_fixedPointValue=(2.5 * 2^8);
	static const int	_fractionalBits = 8;
	int a = 1;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif

Fixed a = Fiexd();

Fixed c(a);

Fiexed b = a;
