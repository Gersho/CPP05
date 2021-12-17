/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:11:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/17 18:30:01 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat hermes("Hermes Conrad", 3);
	Bureaucrat morgan("Morgan Proctor", 148);

	std::cout << hermes << std::endl;
	hermes.promote();
	hermes.promote();
	hermes.promote();
	std::cout << hermes << std::endl;
	hermes.promote();
	hermes.promote();
	hermes.promote();
	std::cout << hermes << std::endl;


	std::cout << morgan << std::endl;
	morgan.demote();
	morgan.demote();
	morgan.demote();
	std::cout << morgan << std::endl;
	morgan.demote();
	morgan.demote();
	morgan.demote();
}



/*

First, we start by the smallest cog in the vast bureaucratic machine: the Bureaucrat.

It must have a 
constant name,
 and a grade, that ranges from 1 (highest possible) to 150 (lowest possible).
 Any attempt to create a Bureaucrat with an invalid grade must
throw an exception, which will be either a Bureaucrat::GradeTooHighException or a
Bureaucrat::GradeTooLowException.

You will provide getters for both these attributes (getName and getGrade), and two
functions to increment or decrement the grade. Both these functions will throw the same
exceptions as before if the grade gets too high or too low. Remember, grade 1 is highest,
150 is lowest, so incrementing a grade 3 gives you a grade 2...


You will provide an overload of the <<operator to ostream that outputs something
like <name>, bureaucrat grade <grade>.

Of course, you will provide a main function to prove you did all this well
*/