/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/14 15:40:48 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    // Canonical form functions
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortAndTimeVector(const std::vector<int>& data);
    void sortAndTimeDeque(const std::deque<int>& data);

private:
    void mergeInsertionSort(std::vector<int>& data);
    void mergeInsertionSort(std::deque<int>& data);
    void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result);
    void merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result);
};

#endif // PMERGEME_HPP

