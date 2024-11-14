/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/14 17:02:11 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sortAndTimeVector(const std::vector<int>& data);
	void sortAndTimeDeque(const std::deque<int>& data);

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
		void applyMergeInsertSort(char **av);
		void printBefore();
		void printAfter();
	};

	class exception : public std::exception {
		public:
			exception();
			virtual ~exception() throw();
			virtual const char *what() const throw();
	};
};
