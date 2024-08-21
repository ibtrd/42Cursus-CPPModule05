/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 18:06:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* CONSTRUCTORS ************************************************************* */

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm(SHRUBBERYCREATION_FORM_NAME, SHRUBBERYCREATION_SIGN_GRADE, SHRUBBERYCREATION_EXEC_GRADE)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(SHRUBBERYCREATION_FORM_NAME, SHRUBBERYCREATION_SIGN_GRADE, SHRUBBERYCREATION_EXEC_GRADE)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(SHRUBBERYCREATION_FORM_NAME, SHRUBBERYCREATION_SIGN_GRADE, SHRUBBERYCREATION_EXEC_GRADE)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	this->_target = other._target;
	return (*this);
}

/* GETTERS ****************************************************************** */

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/* EXCEPTIONS *************************************************************** */

/* ************************************************************************** */