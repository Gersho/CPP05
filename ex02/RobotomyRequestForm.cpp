/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:36:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 15:56:55 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("RobotomyRequestForm", 72, 45, "#default#")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade(), src.getTarget())
{
	setSigned(src.getSigned());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "TODO calling RobotomyRequestForm::execute" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */