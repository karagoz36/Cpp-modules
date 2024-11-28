/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:13:06 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/28 13:57:07 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double>	exchangeRates;
	void							loadDatabase(const std::string& dbFile);
	std::string						findClosestDate(const std::string& date);
	bool							isValidDate(const std::string& date) const;
	bool							isLeapYear(int year) const;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dbFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	double getValueOnDate(const std::string& date, double amount);
};
