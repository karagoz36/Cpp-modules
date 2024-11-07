/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:02:12 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/07 18:05:33 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#define MAX_VAL 750

int main() {

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "It saved the same value!!" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//


///////////////////////////////////////////////////////////////
	std::cout << std::endl;
	std::cout << std::endl;
//////////////////////////////////////////////////////////////


	Array<int> intArray(5);

	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 10;
	}
	std::cout << "Integer array elements: ";
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;



	Array<int> copyArray = intArray;
	copyArray[0] = 100;
	std::cout << "Original array after copy modification: ";
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Copy array elements: ";
	for (unsigned int i = 0; i < copyArray.size(); i++) {
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;



	Array<float> floatArray(3);
	floatArray[0] = 1.1f;
	floatArray[1] = 2.2f;
	floatArray[2] = 3.3f;
	std::cout << "Float array elements: ";
	for (unsigned int i = 0; i < floatArray.size(); i++) {
		std::cout << floatArray[i] << " ";
	}
	std::cout << std::endl;



	try {
		intArray[10] = 50;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
