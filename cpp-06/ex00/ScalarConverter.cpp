/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:14:09 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/01 16:02:25 by tkaragoz         ###   ########.fr       */
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
}
