/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:46 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/13 15:45:27 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) { loadDatabase(dbFile); }

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
		throw std::runtime_error("Error: could not open file.");

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

std::string BitcoinExchange::findClosestDate(const std::string& date) {
	std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
	if (it == exchangeRates.begin())
		return (it->first);
	else if (it == exchangeRates.end() || it->first != date)
		it--;
	return (it->first);
}


double BitcoinExchange::getValueOnDate(const std::string& date, double amount) {
	if (amount < 0)
		throw std::invalid_argument("Error: not a positive number.");
	else if (amount < 0 || amount > 1000)
		throw std::invalid_argument("Error: too large a number.");
	std::string closestDate = findClosestDate(date);
	return (amount * exchangeRates[closestDate]);
}



