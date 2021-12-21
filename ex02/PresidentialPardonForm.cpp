/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:36:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 15:57:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("PresidentialPardonForm", 25, 5, "#default#")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade(), src.getTarget())
{
	setSigned(src.getSigned());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		AForm::operator=(rhs);
	}
	return *this;
}




/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "TODO calling PresidentialPardonForm::execute" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */