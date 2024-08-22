/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:10:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 03:17:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;

		virtual void	action(void) const = 0;
		
	public:
		AForm(void);
		AForm(const std::string &, const unsigned int, const unsigned int);
		AForm(const AForm &);

		virtual ~AForm(void);

		AForm	&operator=(const AForm &);

		std::string		getName(void) const;
		bool			getStatus(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecuteGrade(void) const;

		void			beSigned(const Bureaucrat &);
		void			execute(const Bureaucrat &) const;
		
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

		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class UnsignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

# define FORM_DEFAULT_NAME "unnamed form"
# define ALREADY_SIGNED_EXCEPTION "already signed form"
# define UNSIGNED_EXCEPTION "unsigned form"

#endif /* ******************************************************************* */
