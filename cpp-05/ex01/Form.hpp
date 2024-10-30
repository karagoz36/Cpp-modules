/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:41:51 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;

public:
	Form();
	Form(const std::string& name, int gradeSign, int gradeExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void		beSigned(const Bureaucrat& bureaucrat);

	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;

	class		GradeTooHighException;
	class		GradeTooLowException;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
