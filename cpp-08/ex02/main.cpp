/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:16:50 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/12 16:09:42 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Stack elements:" << std::endl;
	MutantStack<int>::iterator mit = mstack.begin();
	MutantStack<int>::iterator mite = mstack.end();
	++mit;
	--mit;
	while (mit != mite)
	{
		std::cout << *mit << std::endl;
		++mit;
	}

	std::cout << "Stack elements in reverse:" << std::endl;
	for (MutantStack<int>::reverse_iterator mrit = mstack.rbegin(); mrit != mstack.rend(); ++mrit) {
		std::cout << *mrit << std::endl;
	}
	std::stack<int> ms(mstack);

/////
std::cout << "----------------" << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::cout << "List elements:" << std::endl;
	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "List elements in reverse:" << std::endl;
	for (std::list<int>::reverse_iterator lrit = mlist.rbegin(); lrit != mlist.rend(); ++lrit) {
		std::cout << *lrit << std::endl;
	}

	return 0;
}
