/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/20 22:33:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat	me("ibertran", 42);
		std::cout << me << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	me("ibertran", 150);
		std::cout << me << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try {
		Bureaucrat	me("ibertran", 1);
		std::cout << me << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try {
		Bureaucrat	me("ibertran", 0);
		std::cout << me << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try {
		Bureaucrat	me("ibertran", 151);
		std::cout << me << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	me("ibertran", 5);
		while (true)
		{
			std::cout << me << std::endl;
			me.upGrade();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try {
		Bureaucrat	me("ibertran", 145);
		while (true)
		{
			std::cout << me << std::endl;
			me.downGrade();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
