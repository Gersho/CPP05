/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 12:30:42 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat hermes("Hermes Conrad", 37);
	Bureaucrat morgan("Morgan Proctor", 19);
	Form a;
	Form b("allo", 155, 10); // Grade is too low
	Form c("a l'huile", -5 , -12); // Grade is too high
	Form planet_contract("Planet Express Contract", 50, 50);
	Form accident_permit("falling accident permit", 30, 30);

	std::cout << std::endl;
	std::cout << planet_contract << std::endl;
	hermes.signForm(planet_contract);
	std::cout << planet_contract << std::endl;
	hermes.signForm(planet_contract);

	std::cout << "##################" << std::endl;

	std::cout << accident_permit << std::endl;
	hermes.signForm(accident_permit);
	std::cout << accident_permit << std::endl;
	morgan.signForm(accident_permit);
	std::cout << accident_permit << std::endl;
}



/*

Now that we have bureaucrats, better give them something to do with their time.
What better occupation than a stack of forms to fill out?

Make a Form class. It has a name, a boolean indicating whether it is signed (at
the beginning, it’s not), a grade required to sign it, and a grade required to execute it.
The name and grades are constant, and all these attributes are private (not protected).

The grades are subject to the same constraints as in the Bureaucrat, and exceptions
will be thrown if any of them are out of bounds, Form::GradeTooHighException and
Form::GradeTooLowException.

Same as before, make getters for all attributes, and an overload of the <<operator
to ostream that completely describes the state of the form.






You will also add a beSigned function that takes a Bureaucrat, and makes the form
signed if the bureaucrat’s grade is high enough. Always remember, grade 1 is better than
grade 2. If the grade is too low, throw a Form::GradeTooLowException.

Also add a signForm function to the Bureaucrat. If the signing is successful, it will
print something like "<bureaucrat> signs <form>", otherwise it will print something
like "<bureaucrat> cannot sign <form> because <reason>".
Add whatever’s needed to test this to your main.


*/