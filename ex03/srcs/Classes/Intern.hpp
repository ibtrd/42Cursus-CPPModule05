/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:38:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 21:37:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &);

		~Intern(void);

		Intern	&operator=(const Intern &);

		AForm	*makeForm(const std::string &, const std::string &);
};

#endif /* ******************************************************************* */
