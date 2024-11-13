/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:05 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/13 17:41:59 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>

class RPN {
private:
	bool	isOperator(char c) const;
	int		performOperation(int operant1, int operand2, char op) const;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN &);
	~RPN();

	int	evaluate(const std::string& expression);
};
