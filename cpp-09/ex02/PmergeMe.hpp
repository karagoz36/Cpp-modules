/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/20 22:00:23 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
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
		std::vector<int> positions;
		std::vector<std::pair<int, int> > vecPair;
		std::vector<int> mainChain;
		std::vector<int> pend;
		std::vector<int> jacobSequence;

		void getIntegerSequence(char **av);
		void createVectorPairs();
		void sortVectorPairs();
		void merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end);
		void mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);
		void createMainChainAndPend();
		int binarySearch(std::vector<int> array, int target, int begin, int end);
		void genJacobInsertionSequence();
		int calculjacobSequence(int n);
		void genPositions();
		void insertToMainChain();

	public:
		PmergeVector();
		~PmergeVector();
		void printBefore();
		void printAfter();
		void applyMergeInsertSort(char **av);
	};

	class exception : public std::exception {
		public:
			exception();
			virtual ~exception() throw();
			virtual const char *what() const throw();
	};
};
