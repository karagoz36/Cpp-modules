/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:40:26 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/27 22:38:59 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char *av[])
{
	clock_t timeVec;
	clock_t timeDeq;
	// clock_t timeList;

	PmergeMe::PmergeVector pmVec;
	PmergeMe::PmergeDeque pmDeq;
	// PmergeMe::PmergeList pmList;

	if (ac == 1) {
		std::cerr << "usage: " << av[0] << " ...numbers" << std::endl;
		return (1);
	}

	try {
		timeVec = clock();
		pmVec.launch(av);
		timeVec = clock() - timeVec;

		timeDeq = clock();
		pmDeq.launch(av);
		timeDeq = clock() - timeDeq;

		// timeList = clock();
		// pmList.launch(av);
		// timeList = clock() - timeList;

		std::cout << "Sort with Vector" << std::endl;
		std::cout << "After: ";
		pmVec.print();
		std::cout << std::endl;


		std::cout << "Sort with Deque" << std::endl;
		std::cout << "After: ";
		pmDeq.print();
		std::cout << std::endl;

		// std::cout << "Sort with List" << std::endl;
		// std::cout << "After: ";
		// pmList.print();
		//std::cout << std::endl;

		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : "
					<< (float)timeVec * 1000 / CLOCKS_PER_SEC << " ms" << std::endl << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : "
					<< (float)timeDeq * 1000 / CLOCKS_PER_SEC << " ms" << std::endl << std::endl;
		// std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : "
		// 			<< (float)timeList * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
