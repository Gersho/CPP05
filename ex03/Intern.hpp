/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:31:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 18:46:42 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		AForm * makeForm(std::string const name, std::string const target);
		Intern &		operator=( Intern const & rhs );

	private:
		static AForm * make_ShrubberyCreationForm(std::string const & target);
		static AForm * make_RobotomyRequestForm(std::string const & target);
		static AForm * make_PresidentialPardonForm(std::string const & target);
};

#endif /* ********************************************************** INTERN_H */