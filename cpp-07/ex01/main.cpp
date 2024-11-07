/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:00:29 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:30 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "utils.hpp"

int main() {
	int	len = 5;

	int	arr[] = {1, 2, 3, 4, 5};
	std::cout << "Original array: ";
	iter(arr, len, printElement);
	std::cout << std::endl;

	iter(arr, len, doubleValue);
	std::cout << "Doubled array: ";
	iter(arr, len, printElement);
	std::cout << std::endl;

	std::string strArr[] = {"Iter function", "iterates", "string arrays", "too", "thanks to template structure"};
	std::cout << "String array: ";
	iter(strArr, len, printElement);
	std::cout << std::endl;

	char charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter(charArr, len, printElement);
	std::cout << std::endl;

	iter(charArr, len, toUpperCase);
	std::cout << "Uppercase char array: ";
	iter(charArr, len, printElement);
	std::cout << std::endl;

	float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::cout << "Original float array: ";
	iter(floatArr, len, printElement);
	std::cout << std::endl;

	iter(floatArr, len, increment);
	std::cout << "Incremented float array: ";
	iter(floatArr, len, printElement);
	std::cout << std::endl;

	return (0);

}
