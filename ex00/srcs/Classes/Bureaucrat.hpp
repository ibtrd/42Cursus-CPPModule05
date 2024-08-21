/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 03:18:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &, const int);
		Bureaucrat(const Bureaucrat &);

		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void			upGrade(void);
		void			downGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat &);

# define BUREAUCRAT_DEFAULT_NAME "unnamed"
# define BUREAUCRAT_DEFAULT_GRADE 150

# define BUREAUCRAT_MIN_GRADE 150
# define BUREAUCRAT_MAX_GRADE 1

# define GRADE_TOO_HIGH_EXCEPTION "Bureaucrat grade too high"
# define GRADE_TOO_LOW_EXCEPTION "Bureaucrat grade too low"

#endif /* ******************************************************************* */
