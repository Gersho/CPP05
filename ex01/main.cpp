/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/04 13:28:25 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	// Bureaucrat a("Hermes Conrad", 37);
	// Bureaucrat b("Morgan Proctor", 19);

	// std::cout << a << std::endl;
	// a.promote();
	// a.promote();
	// a.promote();
	// std::cout << a << std::endl;
	// a.promote();
	// a.promote();
	// a.promote();
	// std::cout << a << std::endl;


	// std::cout << b << std::endl;
	// b.demote();
	// b.demote();
	// b.demote();
	// std::cout << b << std::endl;
	// b.demote();
	// b.demote();
	// b.demote();

	Form a;
	Form b("allo", 155, 10);
	std::cout << "coucou " << std::endl;
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