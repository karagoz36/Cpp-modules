/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:38 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/08 14:21:29 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyFind.hpp"

int main() {
	try {
		std::vector<int> vec;
		for (int i=1; i <= 5; i++)
			vec.push_back(i);
		int searchValue = 3;
		std::vector<int>::iterator it = easyfind(vec, searchValue);
		std::cout << "Found " << searchValue << " in vector at position: " << std::distance(vec.begin(), it) << std::endl;

		std::list<int> lst;
		for (int i=1; i <= 5; i++)
			lst.push_back(i * 10);
		searchValue = 25;
		std::list<int>::iterator itList = easyfind(lst, searchValue);
		std::cout << "Found " << searchValue << "in list at position: " << std::distance(lst.begin(), itList) << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
