/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 17:28:54 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test(
	const std::string &target,
	const std::string &bureaucratName,
	const int bureaucratGrade
	)
{
	try 
	{
		Bureaucrat				bureaucrat(bureaucratName, bureaucratGrade);
		ShrubberyCreationForm	shrub(target);
		RobotomyRequestForm		robot(target);
		PresidentialPardonForm	pres(target);
		std::cout 
			<< bureaucrat << "\n"
			<< shrub << "\n"
			<< robot << "\n"
			<< pres << "\n" << std::endl;

		bureaucrat.signForm(shrub);
		bureaucrat.executeForm(shrub);
		std::cout << shrub << "\n" << std::endl;

		bureaucrat.signForm(robot);
		bureaucrat.executeForm(robot);
		std::cout << robot << "\n" << std::endl;

		bureaucrat.signForm(pres);
		bureaucrat.executeForm(pres);
		std::cout << pres << "\n" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "test failed: " << e.what() << std::endl;
	}
}

int main(void)
{
	srand(time(NULL));
	
	test("beaver", "rgeral", 135);
	std::cout << "\n" << std::endl;

	test("foal", "lrio", 65);
	std::cout << "\n" << std::endl;

	test("nanou", "anfichet", 3);

	try
	{
		Bureaucrat				me("ibertran", 1);
		PresidentialPardonForm	form("cdomet-d");

		std::cout 
			<< me << "\n"
			<< form << "\n" << std::endl;
		me.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << "test failed: " << e.what() << std::endl;
	}
}
