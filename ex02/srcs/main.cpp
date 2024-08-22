/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 18:17:46 by ibertran         ###   ########lyon.fr   */
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

		bureaucrat.signForm(robot);
		bureaucrat.executeForm(robot);

		bureaucrat.signForm(pres);
		bureaucrat.executeForm(pres);
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
}
