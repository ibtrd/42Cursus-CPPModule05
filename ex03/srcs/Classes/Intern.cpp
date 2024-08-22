/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:46 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 21:37:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS ************************************************************* */

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Intern	&Intern::operator=(const Intern &other)
{
	if (this == &other)
		return (*this);
	// Copy instructions
	return (*this);
}

/* ************************************************************************** */

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm	*form[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		NULL
	};

	for (int i = 0; form[i] != NULL; i++)
	{
		if (form[i]->getName() == name)
		{
			for (int j = i + 1; form[j] != NULL; j++)
				delete form[j];
			std::cout << "Intern creates " << name << std::endl;
			return (form[i]);
		}
		else
			delete form[i];
	}
	std::cout << "Intern failed to create " << name << std::endl;
	return (NULL);
}

