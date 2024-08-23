/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 15:04:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>

#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS ************************************************************* */

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm(PRESIDENTIALPARDON_FORM_NAME, PRESIDENTIALPARDON_SIGN_GRADE, PRESIDENTIALPARDON_EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(PRESIDENTIALPARDON_FORM_NAME, PRESIDENTIALPARDON_SIGN_GRADE, PRESIDENTIALPARDON_EXEC_GRADE)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(PRESIDENTIALPARDON_FORM_NAME, PRESIDENTIALPARDON_SIGN_GRADE, PRESIDENTIALPARDON_EXEC_GRADE)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	this->_target = other._target;
	return (*this);
}

/* ************************************************************************** */

void 	PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

/* GETTERS ****************************************************************** */

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
