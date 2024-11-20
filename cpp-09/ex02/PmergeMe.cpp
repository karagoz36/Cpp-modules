/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/20 20:01:55 by tkaragoz         ###   ########.fr       */
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

void PmergeMe::PmergeVector::applyMergeInsertSort(char **av) {
	this->getIntegerSequence(av);

	if (this->vec.size() == 1)
		this->mainChain.push_back(this->vec.at(0));
	else {
		this->createVectorPairs();
		this->sortVectorPairs();
		this->mergeSort(this->vecPair, 0, this->vecPair.size() - 1);
		this->createMainChainAndPend();
		this->insertToMainChain();
	}
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
		if (leftArray[leftIndex].first <= rightArray[rigtIndex].first) {
			array[mergedIndex] = leftArray[leftIndex];
			leftIndex++;
		} else {
			array[mergedIndex] = rightArray[rigtIndex];
			rigtIndex++;
		}
		mergedIndex++;
	}
	while (leftIndex < leftArray.size()) {
		array[mergedIndex] = leftArray[leftIndex];
		leftIndex++;
		mergedIndex++;
	}
	while (rigtIndex < rightArray.size()) {
		array[mergedIndex] = rightArray[rigtIndex];
		rigtIndex++;
		mergedIndex++;
	}
}

void PmergeMe::PmergeVector::mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end) {
	int	mid;

	if (begin >= end)
		return ;
	mid = begin + (end - begin) / 2;
	this->mergeSort(array, begin, mid);
	this->mergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void PmergeMe::PmergeVector::createMainChainAndPend() {
	int	i = 0;

	mainChain.push_back(this->vecPair.at(0).second); // adds to mainchain first element of first pair

	while (i < this->vecPair.size()) {
		mainChain.push_back(this->vecPair.at(i).first);
		pend.push_back(this->vecPair.at(i).second);
		i++;
	}
}

void PmergeMe::PmergeVector::insertToMainChain() {
	std::vector<int>::iterator it;
	int target;
	int endPos;
	int addedCount;
	int pos;

	this->genPositions();

	for(it = this->positions.begin(); it < this->positions.end(); it++) {
		target = this->pend.at(*it - 1);

		endPos = *it + addedCount;
		pos = this->binarySearch(this->mainChain, target, 0, endPos);
		this->mainChain.insert(this->mainChain.begin() + pos, target);
		addedCount++;
	}

	if (this->vec.size() % 2) {
		target = this->vec.at(this->vec.size() - 1);
		pos = this->binarySearch(this->mainChain, target, 0, this->mainChain.size() - 1);
		this->mainChain.insert(this->mainChain.begin() + pos, target);
	}

}

int PmergeMe::PmergeVector::binarySearch(std::vector<int> array, int target, int begin, int end) {
	int mid;

	while (begin <= end) {
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::PmergeVector::genPositions() {
	int	val = 1;
	int	pos;
	int	lastPos = 1;
	int	i = 0;

	if (this->pend.empty())
		return ;
	this->genJacobInsertionSequence();
	while (i < this->jacobSequence.size()) {
		val = this->jacobSequence.at(i);
		this->positions.push_back(val);

		// 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20 ....
		pos = val - 1;
		while (pos > lastPos)
			this->positions.push_back(pos--);

		lastPos = val;
		i++;
	}
	while (val++ < this->pend.size())
		this->positions.push_back(val);
}

void PmergeMe::PmergeVector::genJacobInsertionSequence() {
	int	size;
	int	jIndex;
	int	index;

	size = this->pend.size();
	index = 3;
	while ((jIndex = this->calculjacobSequence(index)) < size - 1) {
		this->jacobSequence.push_back(jIndex);
		index++;
	}
}

int PmergeMe::PmergeVector::calculjacobSequence(int n) {
	//Jn = (Jn−1) + 2 * (Jn−2) -> 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365...
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return (calculjacobSequence(n - 1) + 2 * calculjacobSequence(n - 2));
}
