/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/19 01:23:12 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define BUREAUCRAT_DEFAULT_NAME "unnamed"
# define BUREAUCRAT_DEFAULT_GRADE 150

# define BUREAUCRAT_MIN_GRADE 150
# define BUREAUCRAT_MAX_GRADE 1

class Bureaucrat
{
	private:
		const std::string	_name;
		__uint8_t			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string &, const __uint8_t);

		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &);

		std::string		getName(void) const;
		__uint8_t		getGrade(void) const;

		void			upGrade(void);
		void			downGrade(void);
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat &);

#endif /* ******************************************************************* */
