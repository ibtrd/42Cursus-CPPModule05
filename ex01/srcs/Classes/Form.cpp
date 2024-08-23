/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:10:39 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/23 04:03:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* CONSTRUCTORS & DESTRUCTOR ************************************************ */

Form::Form(void)
	: _name(FORM_DEFAULT_NAME),
	_signGrade(BUREAUCRAT_DEFAULT_GRADE),
	_executeGrade(BUREAUCRAT_DEFAULT_GRADE)
{
	this->_signed = false;
}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int executeGrade)
	: _name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (signGrade < BUREAUCRAT_MAX_GRADE || executeGrade < BUREAUCRAT_MAX_GRADE)
		throw GradeTooHighException();
	else if (signGrade > BUREAUCRAT_MIN_GRADE || executeGrade > BUREAUCRAT_MIN_GRADE)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form &other)
	: _name(other.getName()),
	_signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade())
{
	*this = other;
}

Form::~Form(void) {}

/* ASIGNMENT OPERATOR ******************************************************* */

Form	&Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	this->_signed = other.getStatus();
	return (*this);
}

/* ************************************************************************** */

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

/* GETTERS ****************************************************************** */

std::string	Form::getName(void) const {
	return (this->_name);
}

bool		Form::getStatus(void) const {
	return (this->_signed);
}

unsigned int Form::getSignGrade(void) const {
	return (this->_signGrade);
}

unsigned int Form::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

/* EXCEPTIONS *************************************************************** */

const char *Form::GradeTooHighException::what() const throw() {
	return (GRADE_TOO_HIGH_EXCEPTION);
}

const char *Form::GradeTooLowException::what() const throw() {
	return (GRADE_TOO_LOW_EXCEPTION);
}

const char *Form::AlreadySignedException::what() const throw() {
	return (ALREADY_SIGNED_EXCEPTION);
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", ";
	if (form.getStatus()) {
		os << "signed form, sign grade ";
	} else {
		os << "unsigned form, sign grade ";
	}
	os << form.getSignGrade() << ", execute grade " << form.getExecuteGrade();
	return (os);
}
