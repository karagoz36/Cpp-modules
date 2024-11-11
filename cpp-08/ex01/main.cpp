/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:47:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/11 18:44:42 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void) {
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::vector<int> vec;
		for(int i=0; i< 10000; i++)
			vec.push_back(i);

		Span test(10000);
		test.addNumbers(vec.begin(), vec.end());
		std::cout << "TESTShortest Span:" << test.shortestSpan() << std::endl;
		std::cout << "TESTLongest Span: " << test.longestSpan() << std::endl;


		std::cout << "Shortest Span:" << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		Span sp_copy(sp);
		std::cout << "Shortest Span (Copy): " << sp_copy.shortestSpan() << std::endl;

		Span sp_assgn;
		sp_assgn = sp;
		std::cout << "Longest Span (Assigned): " << sp_assgn.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
