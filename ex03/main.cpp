/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 18:49:50 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	//AForm z; //impossible because abstract
	Bureaucrat hermes("Hermes Conrad", 150);
	Bureaucrat morgan("Morgan Proctor", 1);
	Intern intern;

	AForm *a = intern.makeForm("ShrubberyCreationForm", "home");
	AForm *b = intern.makeForm("RobotomyRequestForm", "someone");
	AForm *c = intern.makeForm("PresidentialPardonForm","For any mistake that may have been made the person wrote this code");
	AForm *d = intern.makeForm("LotteryWinningTicket", "me");
	(void) d;
	if (!a || !b || !c)
		return (-1);

	std::cout << std::endl;
	hermes.signForm(*a);
	hermes.executeForm(*a);
	morgan.signForm(*a);
	hermes.executeForm(*a);
	morgan.executeForm(*a);
	std::cout << std::endl;
	hermes.signForm(*b);
	hermes.executeForm(*b);
	morgan.signForm(*b);
	hermes.executeForm(*b);
	morgan.executeForm(*b);
	std::cout << std::endl;
	hermes.signForm(*c);
	hermes.executeForm(*c);
	morgan.signForm(*c);
	hermes.executeForm(*c);
	morgan.executeForm(*c);

	delete a;
	delete b;
	delete c;
}



/*

You’re going to create the Intern class.
The intern has no name, no grade, no defining characteristics whatsoever, we only care that it does its job.

The intern has one important thing, the makeForm function. It takes two strings, the
first representing the name of a form, and 
the second one being the target for the form.
It will return, as a pointer to Form, a pointer to whichever concrete form class is represented
by the first parameter, initialized with the second parameter. 

It will print something like
"Intern creates <form>" to the standard output.

If it’s using a worse method, like
if/elseif/elseif/else branchings, or some other ugly stuff like this, it will not be accepted
during the evaluation. If the requested form is not known, print an explicit error message.

*/