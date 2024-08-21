/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:10:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 02:55:31 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form(void);
		Form(const std::string &, const unsigned int, const unsigned int);
		Form(const Form &);

		~Form(void);

		Form	&operator=(const Form &);

		std::string		getName(void) const;
		bool			getStatus(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecuteGrade(void) const;

		void			beSigned(const Bureaucrat &);
		
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

		class AlreadySignedException : public std::exception
		{
			private:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

# define FORM_DEFAULT_NAME "unnamed form"
# define ALREADY_SIGNED_EXCEPTION "already signed form"

#endif /* ******************************************************************* */
