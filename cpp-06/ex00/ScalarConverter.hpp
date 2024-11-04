/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:04:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/04 15:50:58 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
public:
	static void convert(const std::string &s);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter& operator=(ScalarConverter const &);
	~ScalarConverter();

	static bool isChar(const std::string &s);
	static bool isInt(const std::string &s);
	static bool isFloat(const std::string &s);
	static bool isDouble(const std::string &s);
	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);

};
