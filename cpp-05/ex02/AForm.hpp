/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:04:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 19:20:07 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
protected:


private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;

public:
	AForm();
	AForm(const std::string& name, int gradeSign, int gradeExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	virtual void execute(const Bureaucrat& executor) const = 0;

	void		beSigned(const Bureaucrat& bureaucrat);

	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;

	class		GradeTooHighException;
	class		GradeTooLowException;
	class		FormNotSignedException;
};

std::ostream&	operator<<(std::ostream& os, const AForm& aform);
