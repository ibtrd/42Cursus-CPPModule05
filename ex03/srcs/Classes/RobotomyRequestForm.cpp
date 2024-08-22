/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 15:04:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

/* CONSTRUCTORS ************************************************************* */

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm(ROBOTOMYREQUEST_FORM_NAME, ROBOTOMYREQUEST_SIGN_GRADE, ROBOTOMYREQUEST_EXEC_GRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(ROBOTOMYREQUEST_FORM_NAME, ROBOTOMYREQUEST_SIGN_GRADE, ROBOTOMYREQUEST_EXEC_GRADE)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(ROBOTOMYREQUEST_FORM_NAME, ROBOTOMYREQUEST_SIGN_GRADE, ROBOTOMYREQUEST_EXEC_GRADE)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	this->_target = other._target;
	return (*this);
}

/* ************************************************************************** */

void 	RobotomyRequestForm::action(void) const
{
	std::cout << "*DILLING NOISES*\n";
	if (rand() % 2) {
		std::cout << this->_target << " has been robotomized!" << std::endl;
	}
	else {
		std::cout << this->_target << " robotomy  failed!" << std::endl;
	}
}

/* GETTERS ****************************************************************** */

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

/* ************************************************************************** */