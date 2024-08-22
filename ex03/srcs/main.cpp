/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 22:37:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Intern.hpp"

void	test(
	const std::string &formName,
	const std::string &target,
	Bureaucrat &bureaucrat,
	Intern &intern
	)
{
	AForm	*form;

	form = intern.makeForm(formName, target);
	if (form)
	{
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}	
}

int main(void)
{
	srand(time(NULL));
	
	Intern		intern;
	try {
		Bureaucrat	bureaucrat("mjuffard", 0);

		test("shrubbery creation", "home", bureaucrat, intern);
		std::cout << std::endl;
		test("robotomy request", "home", bureaucrat, intern);
		std::cout << std::endl;
		test("presidential pardon", "home", bureaucrat, intern);
		std::cout << std::endl;
		test("dlkdjkdfjgfdgjdgf", "home", bureaucrat, intern);
	}
	catch (std::exception &e) {
		std::cout << "test failure: " << e.what() << std::endl;
	}
}
