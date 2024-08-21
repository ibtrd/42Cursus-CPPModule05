/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 17:13:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h>

void	trySign(const char n, const unsigned int signGrade, const unsigned int executeGrade)
{
	std::string formName = "form-";
	formName += n;
	try {
		Bureaucrat	me("ibertran", 42);
		std::cout << me << std::endl;
		AForm		form(formName, signGrade, executeGrade);
		std::cout << form << std::endl;
		me.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << formName << " " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	tryForm(const char n, const unsigned int signGrade, const unsigned int executeGrade)
{
	std::string formName = "form-";
	formName += n;
	try {
		AForm	form(formName, signGrade, executeGrade);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << formName << " " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	char n = 'A';

	tryForm(n++, 42, 42);
	tryForm(n++, 150, 1);
	tryForm(n++, 1, 150);

	tryForm(n++, 151, 42);
	tryForm(n++, 0, 42);
	tryForm(n++, 42, 151);
	tryForm(n++, 42, 0);

	trySign(n++, 5, 21);
	trySign(n++, 65, 21);
	trySign(n++, 42, 21);

	std::string formName = "form-";
	formName += n;
	try {
		Bureaucrat	me("ibertran", 42);
		std::cout << me << std::endl;
		AForm		form(formName, 42, 21);
		std::cout << form << std::endl;
		me.signForm(form);
		std::cout << form << std::endl;
		me.signForm(form);
	} catch (std::exception &e) {
		std::cout << formName << " " << e.what() << std::endl;
	}
}
