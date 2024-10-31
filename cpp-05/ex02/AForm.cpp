/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:17:41 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/31 15:40:03 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeSign(1), _gradeExecute(1) {
	std::cout << *this << " is created" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
		if (gradeSign < 1 || gradeExecute < 1)
			throw (GradeTooHighException());
		else if (gradeSign > 150 || gradeExecute > 150)
			throw (GradeTooLowException());
	std::cout << *this << " is created" << std::endl;
};

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
		//std::cout << *this << " is created by form copy constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	//std::cout << *this << " is copied by assignement operator" << std::endl;
	return (*this);
}

AForm::~AForm() {
	//std::cout << *this << " is destroyed by form destructor" << std::endl;
}

std::string AForm::getName() const {
	return (_name);
}

bool AForm::isSigned() const {
	return (_isSigned);
}

int	AForm::getGradeSign() const {
	return (_gradeSign);
}

int AForm::getGradeExecute() const {
	return (_gradeExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os	<< "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form. getGradeSign()
		<< ", Grade to execute: " << form.getGradeExecute();
	return (os);
}

const char* AForm::GradeTooHighException::what() const throw() {
		return ("Grade is too high for this form!");
}

const char* AForm::GradeTooLowException::what() const throw() {
		return ("Grade is too low for this form!");
}

const char* AForm::NotSignedException::what() const throw() {
		return ("Form is not signed!");
}
