/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:56 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/14 15:38:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return 1;
    }

    std::vector<int> vecData;
    std::deque<int> deqData;

    for (int i = 1; i < argc; ++i) {
        int number;
        std::istringstream iss(argv[i]);
        if (!(iss >> number) || number < 0) {
            std::cerr << "Error: Invalid input. Only positive integers are allowed." << std::endl;
            return 1;
        }
        vecData.push_back(number);
        deqData.push_back(number);
    }

    PmergeMe sorter;

    // Displaying unsorted data
    std::cout << "Unsorted data: ";
    for (std::vector<int>::iterator it = vecData.begin(); it != vecData.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sorting and timing
    sorter.sortAndTimeVector(vecData);
    sorter.sortAndTimeDeque(deqData);

    // Displaying sorted data
    std::cout << "Sorted data: ";
    for (std::vector<int>::iterator it = vecData.begin(); it != vecData.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
