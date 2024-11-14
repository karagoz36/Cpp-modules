/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/14 15:40:45 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime> // C++98 uyumlu zaman ölçümü için

// Canonical form: Constructor, Copy Constructor, Assignment Operator, Destructor
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {
    // No dynamic resources, so nothing special needed
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        // No dynamic resources, nothing to assign
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Merge-Insertion Sort for std::vector
void PmergeMe::mergeInsertionSort(std::vector<int>& data) {
    if (data.size() < 2) return;
    size_t mid = data.size() / 2;
    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());

    mergeInsertionSort(left);
    mergeInsertionSort(right);
    merge(left, right, data);
}

// Merge-Insertion Sort for std::deque
void PmergeMe::mergeInsertionSort(std::deque<int>& data) {
    if (data.size() < 2) return;
    size_t mid = data.size() / 2;
    std::deque<int> left(data.begin(), data.begin() + mid);
    std::deque<int> right(data.begin() + mid, data.end());

    mergeInsertionSort(left);
    mergeInsertionSort(right);
    merge(left, right, data);
}

// Merge function for std::vector
void PmergeMe::merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result) {
    result.clear();
    std::vector<int>::iterator l = left.begin();
    std::vector<int>::iterator r = right.begin();

    while (l != left.end() && r != right.end()) {
        if (*l < *r) result.push_back(*l++);
        else result.push_back(*r++);
    }
    result.insert(result.end(), l, left.end());
    result.insert(result.end(), r, right.end());
}

// Merge function for std::deque
void PmergeMe::merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result) {
    result.clear();
    std::deque<int>::iterator l = left.begin();
    std::deque<int>::iterator r = right.begin();

    while (l != left.end() && r != right.end()) {
        if (*l < *r) result.push_back(*l++);
        else result.push_back(*r++);
    }
    result.insert(result.end(), l, left.end());
    result.insert(result.end(), r, right.end());
}

// Timing sort for std::vector
void PmergeMe::sortAndTimeVector(const std::vector<int>& data) {
    std::vector<int> dataCopy = data;
    std::clock_t start = std::clock();
    mergeInsertionSort(dataCopy);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to sort using std::vector: " << duration << " microseconds" << std::endl;
}

// Timing sort for std::deque
void PmergeMe::sortAndTimeDeque(const std::deque<int>& data) {
    std::deque<int> dataCopy = data;
    std::clock_t start = std::clock();
    mergeInsertionSort(dataCopy);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to sort using std::deque: " << duration << " microseconds" << std::endl;
}

