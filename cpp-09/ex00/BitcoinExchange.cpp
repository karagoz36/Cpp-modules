/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:46 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/28 13:57:28 by tkaragoz         ###   ########.fr       */
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
			if (isValidDate(date)) {
				exchangeRates[date] = rate;
			} else {
				std::cerr << "Skipping invalid date: " << date << std::endl;
			}
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	int y, m, d, maxDay;

	if (sscanf(date.c_str(), "%4d-%2d-%2d", &y, &m, &d) != 3)
		return false;
	else if (y < 2009 || (y > 2024 || (y == 2024 && m > 11)))
		return false;
	else if (m < 1 || m > 12)
		return false;
	switch (m) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxDay = 31;
			break;
		case 4: case 6: case 9: case 11:
			maxDay = 30;
			break;
		case 2:
			maxDay = isLeapYear(y) ? 29 : 28;
			break;
		default:
			return (false);
	}
	if (d < 1 || d > maxDay)
		return (false);
	return (true);
}

bool BitcoinExchange::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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



