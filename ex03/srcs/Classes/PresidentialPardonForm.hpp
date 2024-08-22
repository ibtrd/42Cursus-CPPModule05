/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/22 16:03:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &);
		PresidentialPardonForm(const PresidentialPardonForm &);

		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);

		std::string		getTarget(void) const;

		void	action(void) const;
};

# define PRESIDENTIALPARDON_FORM_NAME "presidential pardon"
# define PRESIDENTIALPARDON_SIGN_GRADE 25
# define PRESIDENTIALPARDON_EXEC_GRADE 5

#endif /* ******************************************************************* */
