/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:50 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/05 18:05:52 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;

	data.value = 42;
	data.name = "Example";
	std::cout << "Number " << data.value << " | " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data: ";
	std::cout << "Value-> " << deserializedData->value << " | " ;
	std::cout << "Name-> " << deserializedData->name << std::endl;

	if (deserializedData == &data) {
		std::cout << "Success: Deserialized pointer matches the original pointer!" << std::endl;
	} else {
		std::cout << "Error: Deserialized pointer doest not match the original pointer!" << std::endl;
	}

	return (0);
}
