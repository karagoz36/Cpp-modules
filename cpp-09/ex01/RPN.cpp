/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:23:50 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/13 17:49:35 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {}
	return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int operand1, int operand2, char op) const {
	switch (op)	{
		case '+': return (operand1 + operand2);
		case '-': return (operand1 - operand2);
		case '*': return (operand1 * operand2);
		case '/':
			if (operand2 == 0)
				throw std::runtime_error("Error: division by zero.");
			return (operand1 / operand2);
		default: throw std::invalid_argument("Error: unknown operator.");
	}
}

int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
			if (stack.size() < 2)
				throw std::runtime_error("Error: insufficient values for operation.");
			int operand2 = stack.top(); stack.pop();
			int operand1 = stack.top(); stack.pop();
			int result = performOperation(operand1, operand2, token[0]);
			stack.push(result);
		} else if (std::isdigit(token[0])) {
			std::istringstream tokenStream(token);
			int number;
			tokenStream >> number;
			stack.push(number);
		} else {
			throw std::invalid_argument("Error: invalid token in expression.");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid RPN expression.");

	return stack.top();
}
