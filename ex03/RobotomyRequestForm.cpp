/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:36:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 16:15:16 by kzennoun         ###   ########lyon.fr   */
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
	srand(std::time(NULL));
	int num = rand() % 2;

	std::cout << "*drill drill brrzzz drill drill*" << std::endl;
	if (num)
		std::cout << getTarget() <<" has been robotomized successfully." << std::endl;
	else
		std::cout << getTarget() <<" robotomy has failed." << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */