/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 03:12:35 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/21 01:38:19 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


void replaceStrings(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2) {
	std::string line;
	while (std::getline(infile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return (EXIT_FAILURE);
	}
	std:: string filename = argv[1];
	std:: string s1 = argv[2];
	std:: string s2 = argv[3];

	if (s1.empty() || s2.empty()) {
		std::cerr << "Error: strings must not be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: could not create output file" << std::endl;
		return (EXIT_FAILURE);
	}
	replaceStrings(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return (EXIT_SUCCESS);
}
