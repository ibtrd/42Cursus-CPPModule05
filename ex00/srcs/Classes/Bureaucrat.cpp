/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 00:46:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTORS ************************************************************* */

Bureaucrat::Bureaucrat(void) : _name(BUREAUCRAT_DEFAULT_NAME)
{
	this->_grade = BUREAUCRAT_DEFAULT_GRADE;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) :
	_name(name)
{
	if (grade < BUREAUCRAT_MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > BUREAUCRAT_MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
}
/* DESTRUCTOR *************************************************************** */

Bureaucrat::~Bureaucrat(void) {}

/* ASIGNMENT OPERATOR ******************************************************* */

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}

/* ************************************************************************** */

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::upGrade(void)
{
	if (this->_grade == BUREAUCRAT_MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::downGrade(void)
{
	if (this->_grade == BUREAUCRAT_MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &ref)
{
	stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (stream);
}

/* EXCEPTIONS *************************************************************** */

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (GRADE_TOO_HIGH_EXCEPTION);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (GRADE_TOO_LOW_EXCEPTION);
}
