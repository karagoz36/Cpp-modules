/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/27 22:34:04 by tkaragoz         ###   ########.fr       */
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

PmergeMe::exception::exception() {}

PmergeMe::exception::~exception() throw() {}

const char *PmergeMe::exception::what() const throw() {
	return ("Error");
}

//////////////////////////////////
//////////////STD:VECTOR///////////
///////////////////////////////////

PmergeMe::PmergeVector::PmergeVector() {}

PmergeMe::PmergeVector::~PmergeVector() {}

void PmergeMe::PmergeVector::launch(char **av) {
	this->getIntegerSequence(av);
	std::cout << "Before: ";
	print();
	std::cout << std::endl;
	this->MergeInsertSort(this->vec.begin(), this->vec.end());
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

void PmergeMe::PmergeVector::MergeInsertSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	if (std::distance(begin, end) <= 1) return;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> leftover;

	std::vector<int>::iterator it = begin;
	while(std::distance(it, end) >= 2) {
		int first_val = *(it++);
		int second_val = *(it++);
		if (second_val < first_val)
			std::swap(first_val, second_val);
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	if (it != end)
		leftover.push_back(*it);

	std::vector<int> mainChain;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		mainChain.push_back(it->second);
	if (mainChain.size() >= 2)
		MergeInsertSort(mainChain.begin(), mainChain.end());

	std::vector<int> pend;
	for (std::vector<int>::iterator mc_it = mainChain.begin(); mc_it != mainChain.end(); ++mc_it) {
		for (std::vector<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
			if (p_it->second == *mc_it) {
				pend.push_back(p_it->first);
				break;
			}
		}
	}

	std::vector<int> positions = genPositions(pend.size());
	for (int i = 0; i < static_cast<int>(positions.size()); i++) {
		std::vector<int>::iterator target = pend.begin();
		if (positions[i] == 1) {
			mainChain.insert(mainChain.begin(), *target);
		} else {
			std::advance(target, positions[i] - 1);
			int t_value;
			for (std::vector<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); p_it++) {
				if (p_it->first == *target) {
					t_value = p_it->second;
					break;
				}
			}
			std::vector<int>::iterator searchEnd;
			for (searchEnd = mainChain.begin(); searchEnd != mainChain.end(); searchEnd++)
				if (*searchEnd == t_value) break;
			std::vector<int>::iterator final_pos = binarySearch(mainChain.begin(), searchEnd, *target);
			mainChain.insert(final_pos, *target);
		}
	}
	if (!leftover.empty()) {
		std::vector<int>::iterator final_pos = binarySearch(mainChain.begin(), mainChain.end(), *leftover.begin());
		mainChain.insert(final_pos, *leftover.begin());
	}

	std::copy(mainChain.begin(), mainChain.end(), begin);
}

std::vector<int>::iterator PmergeMe::PmergeVector::binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {

	std::vector<int>::iterator it;
	std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
	count = std::distance(begin, end);

	while (count > 0) {
		it = begin;
		step = count / 2;
		std::advance(it, step);

		if (*it < target) {
			begin = ++it;
			count -= step + 1;
		} else
			count = step;
	}
	return begin;
}

std::vector<int> PmergeMe::PmergeVector::genPositions(int n) {
	//1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20 ....
	std::vector<int> jacobSeq = genJacobSeq(n);
	std::vector<int> positions;
	if (n == 0)
		return (positions);
	positions.push_back(1);
	if (n == 1)
		return (positions);
	for (int i = 1; i < static_cast<int>(jacobSeq.size()); i++) {
		if (jacobSeq[i] > positions.back()) {
			int tmp = jacobSeq[i - 1];
			positions.push_back(jacobSeq[i]);
			for (int j = jacobSeq[i] - 1; j > tmp; j--)
				positions.push_back(j);
		}
	}
	for (int i = n; i > jacobSeq.back(); i--)
		positions.push_back(i);
	return (positions);
}

std::vector<int> PmergeMe::PmergeVector::genJacobSeq(int n) {
	//Jn = (Jn−1) + 2 * (Jn−2) -> 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365...
	std::vector<int> jacobSeq;

	if (n == 0) return (jacobSeq);
	jacobSeq.push_back(0);
	if (n == 1) return (jacobSeq);
	jacobSeq.push_back(1);

	int prev = 0;
	int curr = 1;

	while (true) {
		int next = curr + 2 * prev;
		if (next > n) break;
		jacobSeq.push_back(next);
		prev = curr;
		curr = next;
	}
	return (jacobSeq);
}

void PmergeMe::PmergeVector::print()
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//////////////////////////////////
//////////////STD:DEQUE////////////
///////////////////////////////////

PmergeMe::PmergeDeque::PmergeDeque() {}

PmergeMe::PmergeDeque::~PmergeDeque() {}

void PmergeMe::PmergeDeque::launch(char **av) {
	this->getIntegerSequence(av);
	this->MergeInsertSort(this->deq.begin(), this->deq.end());
}

void PmergeMe::PmergeDeque::getIntegerSequence(char **av) {
	int i = 1;
	char *ptr;
	while (av[i]) {
		if (!*av[i])
			throw(PmergeMe::exception());
		int val = strtol(av[i], &ptr, 10);
		if (*ptr || val < 0)
			throw(PmergeMe::exception());
		this->deq.push_back(val);
		i++;
	}
}

void PmergeMe::PmergeDeque::MergeInsertSort(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	if (std::distance(begin, end) <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> leftover;

	std::deque<int>::iterator it = begin;
	while (std::distance(it, end) >= 2) {
		int first_val = *(it++);
		int second_val = *(it++);
		if (second_val < first_val)
			std::swap(first_val, second_val);
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	if (it != end)
		leftover.push_back(*it);

	std::deque<int> mainChain;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		mainChain.push_back(it->second);
	if (mainChain.size() >= 2)
		MergeInsertSort(mainChain.begin(), mainChain.end());

	std::deque<int> pend;
	for (std::deque<int>::iterator mc_it = mainChain.begin(); mc_it != mainChain.end(); ++mc_it) {
		for (std::deque<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
			if (p_it->second == *mc_it) {
				pend.push_back(p_it->first);
				break;
			}
		}
	}

	std::deque<int> positions = genPositions(pend.size());
	for (size_t i = 0; i < positions.size(); i++) {
		std::deque<int>::iterator target = pend.begin();
		if (positions[i] == 1) {
			mainChain.push_front(*target);
		} else {
			std::advance(target, positions[i] - 1);
			int t_value;
			for (std::deque<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
				if (p_it->first == *target) {
					t_value = p_it->second;
					break;
				}
			}
			std::deque<int>::iterator searchEnd;
			for (searchEnd = mainChain.begin(); searchEnd != mainChain.end(); ++searchEnd)
				if (*searchEnd == t_value) break;
			std::deque<int>::iterator final_pos = binarySearch(mainChain.begin(), searchEnd, *target);
			mainChain.insert(final_pos, *target);
		}
	}
	if (!leftover.empty()) {
		std::deque<int>::iterator final_pos = binarySearch(mainChain.begin(), mainChain.end(), *leftover.begin());
		mainChain.insert(final_pos, *leftover.begin());
	}

	std::copy(mainChain.begin(), mainChain.end(), begin);
}


std::deque<int>::iterator PmergeMe::PmergeDeque::binarySearch(std::deque<int>::iterator begin, std::deque<int>::iterator end, int target) {
	std::deque<int>::iterator it;
	std::iterator_traits<std::deque<int>::iterator>::difference_type count, step;
	count = std::distance(begin, end);

	while (count > 0) {
		it = begin;
		step = count / 2;
	std::advance(it, step);

		if (*it < target) {
			begin = ++it;
			count -= step + 1;
		} else
			count = step;
	}
	return begin;
}

std::deque<int> PmergeMe::PmergeDeque::genPositions(int n) {
	std::deque<int> jacobSeq = genJacobSeq(n);
	std::deque<int> positions;
	if (n == 0)
		return positions;
	positions.push_back(1);
	if (n == 1)
		return positions;
	for (size_t i = 1; i < jacobSeq.size(); i++) {
		if (jacobSeq[i] > positions.back()) {
			int tmp = jacobSeq[i - 1];
			positions.push_back(jacobSeq[i]);
			for (int j = jacobSeq[i] - 1; j > tmp; j--)
				positions.push_back(j);
		}
	}
	for (int i = n; i > jacobSeq.back(); i--)
		positions.push_back(i);
	return positions;
}

std::deque<int> PmergeMe::PmergeDeque::genJacobSeq(int n) {
	std::deque<int> jacobSeq;
	if (n == 0) return jacobSeq;
	jacobSeq.push_back(0);
	if (n == 1) return jacobSeq;
	jacobSeq.push_back(1);

	int prev = 0, curr = 1;
	while (true) {
		int next = curr + 2 * prev;
		if (next > n) break;
		jacobSeq.push_back(next);
		prev = curr;
		curr = next;
	}
	return jacobSeq;
}

void PmergeMe::PmergeDeque::print() {
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


//////////////////////////////////
//////////////STD:LIST/////////////
///////////////////////////////////

// PmergeMe::PmergeList::PmergeList() {}

// PmergeMe::PmergeList::~PmergeList() {}

// void PmergeMe::PmergeList::launch(char **av) {
// 	this->getIntegerSequence(av);
// 	this->MergeInsertSort(this->lst.begin(), this->lst.end());
// }

// void PmergeMe::PmergeList::getIntegerSequence(char **av) {
// 	int i = 1;
// 	char *ptr;
// 	while (av[i]) {
// 		if (!*av[i])
// 			throw(PmergeMe::exception());
// 		int val = strtol(av[i], &ptr, 10);
// 		if (*ptr || val < 0)
// 			throw(PmergeMe::exception());
// 		this->lst.push_back(val);
// 		i++;
// 	}
// }

// void PmergeMe::PmergeList::MergeInsertSort(std::list<int>::iterator begin, std::list<int>::iterator end) {
// 	if (std::distance(begin, end) <= 1) return;

// 	std::list<std::pair<int, int> > pairs;
// 	std::list<int> leftover;

// 	std::list<int>::iterator it = begin;
// 	while (std::distance(it, end) >= 2) {
// 		int first_val = *(it++);
// 		int second_val = *(it++);
// 		if (second_val < first_val)
// 			std::swap(first_val, second_val);
// 		pairs.push_back(std::make_pair(first_val, second_val));
// 	}
// 	if (it != end)
// 		leftover.push_back(*it);

// 	std::list<int> mainChain;
// 	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
// 		mainChain.push_back(it->second);
// 	if (mainChain.size() >= 2)
// 		MergeInsertSort(mainChain.begin(), mainChain.end());

// 	std::list<int> pend;
// 	for (std::list<int>::iterator mc_it = mainChain.begin(); mc_it != mainChain.end(); ++mc_it) {
// 		for (std::list<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
// 			if (p_it->second == *mc_it) {
// 				pend.push_back(p_it->first);
// 				break;
// 			}
// 		}
// 	}

// 	std::list<int> positions = genPositions(pend.size());
// 	for (std::list<int>::iterator pos_it = positions.begin(); pos_it != positions.end(); ++pos_it) {
// 		std::list<int>::iterator target = pend.begin();
// 		for (int i = 1; i < *pos_it; ++i)
// 			++target;

// 		int t_value;
// 		for (std::list<std::pair<int, int> >::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
// 			if (p_it->first == *target) {
// 				t_value = p_it->second;
// 				break;
// 			}
// 		}

// 		std::list<int>::iterator searchEnd = mainChain.begin();
// 		while (searchEnd != mainChain.end() && *searchEnd != t_value)
// 			++searchEnd;

// 		std::list<int>::iterator final_pos = binarySearch(mainChain.begin(), searchEnd, *target);
// 		mainChain.insert(final_pos, *target);
// 	}

// 	if (!leftover.empty()) {
// 		std::list<int>::iterator final_pos = binarySearch(mainChain.begin(), mainChain.end(), *leftover.begin());
// 		mainChain.insert(final_pos, *leftover.begin());
// 	}

// 	std::copy(mainChain.begin(), mainChain.end(), begin);
// }

// std::list<int>::iterator PmergeMe::PmergeList::binarySearch(std::list<int>::iterator begin, std::list<int>::iterator end, int target) {
// 	std::list<int>::iterator it;
// 	std::iterator_traits<std::list<int>::iterator>::difference_type count, step;
// 	count = std::distance(begin, end);

// 	while (count > 0) {
// 		it = begin;
// 		step = count / 2;
// 		std::advance(it, step); // O(n) maliyetlidir

// 		if (*it < target) {
// 			begin = ++it;
// 			count -= step + 1;
// 		} else
// 			count = step;
// 	}
// 	return begin;
// }

// std::list<int> PmergeMe::PmergeList::genPositions(int n) {
// 	std::list<int> jacobSeq = genJacobSeq(n);
// 	std::list<int> positions;
// 	if (n == 0)
// 		return positions;
// 	positions.push_back(1);
// 	if (n == 1)
// 		return positions;

// 	std::list<int>::iterator it = jacobSeq.begin();
// 	++it;
// 	for (; it != jacobSeq.end(); ++it) {
// 		if (*it > positions.back()) {
// 			int prev = *(--it);
// 			++it;
// 			positions.push_back(*it);
// 			for (int j = *it - 1; j > prev; --j)
// 				positions.push_back(j);
// 		}
// 	}
// 	for (int i = n; i > jacobSeq.back(); --i)
// 		positions.push_back(i);
// 	return positions;
// }

// std::list<int> PmergeMe::PmergeList::genJacobSeq(int n) {
// 	std::list<int> jacobSeq;
// 	if (n == 0) return jacobSeq;
// 	jacobSeq.push_back(0);
// 	if (n == 1) return jacobSeq;
// 	jacobSeq.push_back(1);

// 	int prev = 0, curr = 1;
// 	while (true) {
// 		int next = curr + 2 * prev;
// 		if (next > n) break;
// 		jacobSeq.push_back(next);
// 		prev = curr;
// 		curr = next;
// 	}
// 	return jacobSeq;
// }

// void PmergeMe::PmergeList::print() {
// 	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }
