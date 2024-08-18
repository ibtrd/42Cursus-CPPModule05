/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/19 01:25:17 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTORS ************************************************************* */

Bureaucrat::Bureaucrat(void) : _name(BUREAUCRAT_DEFAULT_NAME)
{
	this->_grade = BUREAUCRAT_DEFAULT_GRADE;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
}

Bureaucrat::Bureaucrat(const std::string &name, const __uint8_t grade) :
	_name(name)
{
	if (grade < BUREAUCRAT_MAX_GRADE || grade > BUREAUCRAT_MIN_GRADE)
		throw ;
	this->_grade = grade;
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

__uint8_t	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::upGrade(void)
{
	if (this->getGrade() == BUREAUCRAT_MAX_GRADE)
		throw ;
	this->_grade--;
}

void		Bureaucrat::downGrade(void)
{
	if (this->getGrade() == BUREAUCRAT_MIN_GRADE)
		throw ;
	this->_grade++;
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &ref)
{
	stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return (stream);
}
