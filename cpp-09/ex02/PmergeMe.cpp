/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/15 13:45:43 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
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
	int	val;
	while (av[i]) {
		if (!*av[i])
			throw(PmergeMe::exception());
		val = strtol(av[i], &ptr, 10);
		if (*ptr || val < 0)
			throw(PmergeMe::exception());
		this->vec.push_back(val);
		i++;
	}
}

void PmergeMe::PmergeVector::createVectorPairs() {
	int				size;
	unsigned int	i;

	i = 0;
	size = this->vec.size() / 2;
	while (size != 0) {
		this->vecPair.push_back(std::make_pair(this->vec.at(i), this->vec.at(i + 1)));
		i += 2;
		size--;
	}
}

void PmergeMe::PmergeVector::sortVectorPairs() {
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < this->vecPair.size()) {
		if (this->vecPair.at(i).first < this->vecPair.at(i).second) {
			tmp = this->vecPair.at(i).first;
			this->vecPair.at(i).first = this->vecPair.at(i).second;
			this->vecPair.at(i).second = tmp;
		}
		i++;
	}
}

void PmergeMe::PmergeVector::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end) {
	int	leftIndex = 0;
	int	rigtIndex = 0;
	int	mergedIndex = begin;

	std::vector<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

	while (leftIndex < leftArray.size() && rigtIndex < rightArray.size()) {
		if (leftArray[leftIndex].first <= rightArray[rigtIndex].first)
	}

}
