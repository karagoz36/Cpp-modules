/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:41:51 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/29 18:59:33 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form {

private:
	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExecute;
	bool				_isSigned;

public:
	Form();
	Form(const std::string& name, int gradeSign, int gradeExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();


	void	beSigned(const Bureaucrat& bureaucrat);

	std::string getName() const;
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
