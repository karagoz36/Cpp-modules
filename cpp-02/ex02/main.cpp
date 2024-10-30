/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:43:18 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 14:33:49 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
    std::cout << "===== Constructors & Basic Assignment =====" << std::endl;
    Fixed a;
    Fixed const b(5.05f);
    Fixed const c(2);
    Fixed d(b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;

    std::cout << "===== Assignment Operator =====" << std::endl;
    a = Fixed(10.1f);
    std::cout << "a after assignment: " << a << std::endl;

    std::cout << "===== Arithmetic Operators =====" << std::endl;
    std::cout << "b + c: " << b + c << std::endl;
    std::cout << "b - c: " << b - c << std::endl;
    std::cout << "b * c: " << b * c << std::endl;
    std::cout << "b / c: " << b / c << std::endl;

    std::cout << "===== Comparison Operators =====" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "===== Increment/Decrement Operators =====" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "Prefix ++a: " << ++a << std::endl;
    std::cout << "a after prefix ++: " << a << std::endl;
    std::cout << "Postfix a++: " << a++ << std::endl;
    std::cout << "a after postfix ++: " << a << std::endl;

    std::cout << "Prefix --a: " << --a << std::endl;
    std::cout << "a after prefix --: " << a << std::endl;
    std::cout << "Postfix a--: " << a-- << std::endl;
    std::cout << "a after postfix --: " << a << std::endl;

    std::cout << "===== Min & Max Functions =====" << std::endl;
    std::cout << "Min between a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max between a and b: " << Fixed::max(a, b) << std::endl;

    Fixed e(1.2345f);
    Fixed f(5.6789f);

    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "Min between e and f: " << Fixed::min(e, f) << std::endl;
    std::cout << "Max between e and f: " << Fixed::max(e, f) << std::endl;

    std::cout << "===== Const Min & Max Functions =====" << std::endl;
    const Fixed g(3.5f);
    const Fixed h(7.5f);

    std::cout << "g: " << g << ", h: " << h << std::endl;
    std::cout << "Const Min between g and h: " << Fixed::min(g, h) << std::endl;
    std::cout << "Const Max between g and h: " << Fixed::max(g, h) << std::endl;

    std::cout << "===== End of Tests =====" << std::endl;

    return 0;
}

