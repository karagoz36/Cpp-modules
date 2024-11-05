/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:29:48 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/05 18:56:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TypeIdentifier.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return ;
	} catch (const std::exception& e) {
		std::cout << "Unknown type" << std::endl;
	}
}
