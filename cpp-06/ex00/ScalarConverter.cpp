/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:14:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/06 13:31:14 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &s) {
	double value = std::strtod(s.c_str(), NULL);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

bool ScalarConverter::isChar(const std::string &s) {
	return (s.length() == 1 && std::isprint(s[0] && !std::isdigit(s[0])));
}

bool ScalarConverter::isInt(const std::string &s) {
	char *end;
	long val;

	val = std::strtol(s.c_str(), &end, 10);
	return (*end == '\0' && val >=std::numeric_limits<int>::min() \
		&& val <=std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &s) {
	return (s.find('f') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string &s) {
	return (!isInt(s) && !isFloat(s));
}

void ScalarConverter::printChar(double value) {
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value) {
	if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
