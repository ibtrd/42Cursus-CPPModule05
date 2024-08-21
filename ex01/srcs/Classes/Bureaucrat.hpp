/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:34 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 02:40:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &, const int);
		Bureaucrat(const Bureaucrat &);

		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &);

		std::string		getName(void) const;
		int		getGrade(void) const;

		void			upGrade(void);
		void			downGrade(void);
		void			signForm(Form &);

		class GradeTooHighException : public std::exception
		{
			private:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat &);

# define BUREAUCRAT_DEFAULT_NAME "unnamed"
# define BUREAUCRAT_DEFAULT_GRADE 150

# define BUREAUCRAT_MIN_GRADE 150
# define BUREAUCRAT_MAX_GRADE 1

# define GRADE_TOO_HIGH_EXCEPTION "grade too high"
# define GRADE_TOO_LOW_EXCEPTION "grade too low"

#endif /* ******************************************************************* */
