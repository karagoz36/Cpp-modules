/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:46 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/12 18:56:23 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) { loadDatabase(dbFile)}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		exchangeRates = other.exchangeRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::__throw_runtime_error("Error: could not open file.");

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		double rate;
		if (std::getline(iss, date, ',') && iss >> rate) {
			exchangeRates[date] = rate;
		}
	}
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {}


double BitcoinExchange::getValueOnDate(const std::string& date, double amount) {}



