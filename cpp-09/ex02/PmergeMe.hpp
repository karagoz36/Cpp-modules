// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   PmergeMe.hpp                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/14 15:35:27 by tkaragoz          #+#    #+#             */
// /*   Updated: 2024/11/27 20:23:44 by tkaragoz         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <ctime>
#include <exception>
#include <cstdlib>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	class PmergeVector {
	private:
		std::vector<int> vec;

		void getIntegerSequence(char **av);
		void MergeInsertSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		std::vector<int>::iterator binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target);
		std::vector<int> genJacobSeq(int n);
		std::vector<int> genPositions(int n);

	public:
		PmergeVector();
		~PmergeVector();
		void print();
		void launch(char **av);
	};

	class PmergeDeque {
	private:
		std::deque<int> deq;

		void getIntegerSequence(char **av);
		void MergeInsertSort(std::deque<int>::iterator begin, std::deque<int>::iterator end);
		std::deque<int>::iterator binarySearch(std::deque<int>::iterator begin, std::deque<int>::iterator end, int target);
		std::deque<int> genJacobSeq(int n);
		std::deque<int> genPositions(int n);

	public:
		PmergeDeque();
		~PmergeDeque();
		void print();
		void launch(char **av);
	};

	// class PmergeList {
	// private:
	// 	std::list<int> lst;

	// 	void getIntegerSequence(char **av);
	// 	void MergeInsertSort(std::list<int>::iterator begin, std::list<int>::iterator end);
	// 	std::list<int>::iterator binarySearch(std::list<int>::iterator begin, std::list<int>::iterator end, int target);
	// 	std::list<int> genJacobSeq(int n);
	// 	std::list<int> genPositions(int n);

	// public:
	// 	PmergeList();
	// 	~PmergeList();
	// 	void print();
	// 	void launch(char **av);
	// };

	class exception : public std::exception {
		public:
			exception();
			virtual ~exception() throw();
			virtual const char *what() const throw();
	};
};
