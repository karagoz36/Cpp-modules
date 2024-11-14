/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/14 17:05:15 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {}
	return (*this);
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::exception::what() const throw() {
	return ("Error");
}

void PmergeMe::PmergeVector::getIntegerSequence(char **av) {
	int		i;
	char	*ptr;

	i = 1;
}
