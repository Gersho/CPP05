/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 16:44:05 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	//AForm z; //impossible because abstract
	Bureaucrat hermes("Hermes Conrad", 150);
	Bureaucrat morgan("Morgan Proctor", 1);
	ShrubberyCreationForm a("home");
	RobotomyRequestForm b("someone");
	PresidentialPardonForm c("For any mistake that may have been made the person wrote this code");

	hermes.signForm(a);
	hermes.executeForm(a);
	morgan.signForm(a);
	hermes.executeForm(a);
	morgan.executeForm(a);
	std::cout << std::endl;
	hermes.signForm(b);
	hermes.executeForm(b);
	morgan.signForm(b);
	hermes.executeForm(b);
	morgan.executeForm(b);
	std::cout << std::endl;
	hermes.signForm(c);
	hermes.executeForm(c);
	morgan.signForm(c);
	hermes.executeForm(c);
	morgan.executeForm(c);
}



/*
Now that you have basic forms, you will make a few forms that actually do something.
Create a few concrete forms:

• ShrubberyCreationForm (Required grades: sign 145, exec 137). Action: Create
a file called <target>_shrubbery, and write ASCII trees inside it, in the current
directory.

• RobotomyRequestForm (Required grades: sign 72, exec 45). Action: Makes some
drilling noises, and tell us that <target> has been robotomized successfully 50% of
the time. Otherwise, tell us it’s a failure.

• PresidentialPardonForm (Required grades: sign 25, exec 5). Action: Tells us
<target> has been pardoned by Zafod Beeblebrox.

All of these will have to take only one parameter in their constructor, which will
represent the target of the form. For example, "home" if you want to plant shrubbery at
home. 
Remember the form’s attributes need to remain private, and in the base class.
Now you need to add a method execute(Bureaucrat const & executor) const to
the base form, and implement a method executing the form’s action in all the concrete
forms.


You have to 
check that the form is signed, and that 
the bureaucrat attempting to execute the form has a high enough grade,
else you will throw an appropriate exception.
Whether you want to make these checks in every concrete class or make the check-in the
base class then calling another method to execute the action is up to you, but one way
is prettier than the other one.


In any event, the base form must be an abstract class.
Finish this by adding an executeForm(Form const & form) function to the bureaucrat.
 It must attempt to execute the form, and if it’s a success, print something like
<bureaucrat> executes <form>. If not, print an explicit error message.
Add whatever you need to your main to test that everything works.


*/