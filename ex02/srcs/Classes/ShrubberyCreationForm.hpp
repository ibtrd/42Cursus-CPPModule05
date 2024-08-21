/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/21 17:52:54 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>

# include  "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &);
		ShrubberyCreationForm(const ShrubberyCreationForm &);

		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);

		std::string		getTarget(void) const;
};

# define SHRUBBERYCREATION_FORM_NAME "shrubbery creation"
# define SHRUBBERYCREATION_SIGN_GRADE 145
# define SHRUBBERYCREATION_EXEC_GRADE 137

#endif /* ******************************************************************* */
