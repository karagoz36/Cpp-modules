/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:27:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/29 18:12:19 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include <stdexcept>

class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	void		incrementGrade();
	void		decrementGrade();

	class		GradeTooHighException;
	class 		GradeTooLowException;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
