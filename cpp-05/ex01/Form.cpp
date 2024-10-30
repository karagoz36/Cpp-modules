/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:17:41 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 18:15:48 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception {
public:
	const char* what() const throw() {
		return ("Grade is too high for this form!");
	}
};

class Form::GradeTooLowException : public std::exception {
public:
	const char* what() const throw() {
		return ("Grade is too low for this form!");
	}
};

Form::Form() : _name("Default Form"), _isSigned(false), _gradeSign(1), _gradeExecute(1) {
	// std::cout << *this << " is created by default form constructor" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
		if (gradeSign < 1 || gradeExecute < 1)
			throw (GradeTooHighException());
		else if (gradeSign > 150 || gradeExecute > 150)
			throw (GradeTooLowException());
	//std::cout << *this << " is created by form constructor" << std::endl;
};

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
		//std::cout << *this << " is created by form copy constructor" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	//std::cout << *this << " is copied by assignement operator" << std::endl;
	return (*this);
}

Form::~Form() {
	//std::cout << *this << " is destroyed by form destructor" << std::endl;
}

std::string Form::getName() const {
	return (_name);
}

bool Form::isSigned() const {
	return (_isSigned);
}

int	Form::getGradeSign() const {
	return (_gradeSign);
}

int Form::getGradeExecute() const {
	return (_gradeExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os	<< "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade required to sign: " << form. getGradeSign()
		<< ",Grade required to execute: " << form.getGradeExecute();
	return (os);
}
