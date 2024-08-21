/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:10:39 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 02:55:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* CONSTRUCTORS & DESTRUCTOR ************************************************ */

AForm::AForm(void)
	: _name(FORM_DEFAULT_NAME),
	_signGrade(BUREAUCRAT_DEFAULT_GRADE),
	_executeGrade(BUREAUCRAT_DEFAULT_GRADE)
{
	this->_signed = false;
}

AForm::AForm(const std::string &name, const unsigned int signGrade, const unsigned int executeGrade)
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

AForm::AForm(const AForm &other)
	: _name(other.getName()),
	_signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade())
{
	*this = other;
}

AForm::~AForm(void) {}

/* ASIGNMENT OPERATOR ******************************************************* */

AForm	&AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	this->_signed = other.getStatus();
	return (*this);
}

/* ************************************************************************** */

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

/* GETTERS ****************************************************************** */

std::string	AForm::getName(void) const {
	return (this->_name);
}

bool		AForm::getStatus(void) const {
	return (this->_signed);
}

unsigned int AForm::getSignGrade(void) const {
	return (this->_signGrade);
}

unsigned int AForm::getExecuteGrade(void) const {
	return (this->_executeGrade);
}

/* EXCEPTIONS *************************************************************** */

const char *AForm::GradeTooHighException::what() const throw() {
	return (GRADE_TOO_HIGH_EXCEPTION);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (GRADE_TOO_LOW_EXCEPTION);
}

const char *AForm::AlreadySignedException::what() const throw() {
	return (ALREADY_SIGNED_EXCEPTION);
}

/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &os, const AForm &form)
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