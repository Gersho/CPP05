/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:31:44 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 18:39:17 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

AForm * Intern::makeForm(std::string name, std::string target)
{
	std::string names_list[] = {
							"ShrubberyCreationForm",
							"RobotomyRequestForm",
							"PresidentialPardonForm"
							};

	AForm* (*func_list[])(std::string const &) = {
					&Intern::make_ShrubberyCreationForm,
					&Intern::make_RobotomyRequestForm,
					&Intern::make_PresidentialPardonForm
							};
	
	for (int i = 0; i < 4; i++)
	{
		if (name == names_list[i])
			return func_list(target);
	}
	std::cout << "Intern does not know how to make form " << name
		<< " proving again how useless he is." << std::endl;
}

AForm * Intern::make_ShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::make_RobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::make_PresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */