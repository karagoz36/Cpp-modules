/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:43:17 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/13 13:26:40 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
	if (argc != 2)
		return (std::cerr << "Error: wrong number of arguments." << std::endl, 1);
	try {
		BitcoinExchange exchange("data.csv");
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
			return (std::cerr << "Error: could not open input file." << std::endl, 1);

		std::string line;
		while (std::getline(inputFile, line)) {
			std::istringstream iss(line);
			std::string date;
			double value;
			if (std::getline(iss, date, '|') && iss >> value) {
				try {
					double result = exchange.getValueOnDate(date, value);
					std::cout << date << " => " << value << " = " << result << std::endl;
				} catch (const std::invalid_argument& e) {
					std::cerr << e.what() << std::endl;
				}
			} else {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
