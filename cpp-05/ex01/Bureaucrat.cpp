/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:34:51 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/30 18:14:10 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
public:
	const char* what() const throw() {
		return ("Grade is too high!");
	}
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
	const char* what() const throw() {
	return ("Grade is too low!");
	}
};

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	//std::cout << *this << " is created by default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	//std::cout << *this << " is created by constructor" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
	//std::cout << *this << " is created by copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	//std::cout << *this << " is created by assignement operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	//std::cout << *this << " is destroyed by destructor" << std::endl;
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << " (bureaucrat grade " << b.getGrade() << ")";
	return (os);
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() <<std::endl;
	}
	catch (const std::exception& e) {
		std::cout	<< _name << " couldn't sign " << form.getName()
					<< " beacause " << e.what() << std::endl;

	}
}
