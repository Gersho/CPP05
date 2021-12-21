/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:36:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 16:52:10 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("ShrubberyCreationForm", 145, 137, "#default#")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	AForm(src.getName(), src.getSignGrade(), src.getExecGrade(), src.getTarget())
{
	setSigned(src.getSigned());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void) executor;

   	std::ofstream out;

	out.open((getTarget() + "_shrubbery").c_str());
	if (!out)
	{
		std::cerr << "Could not open output file." << std::endl;
	}
 
	out	<< "         &&& &&  & &&"				<< std::endl
		<< "     && &+/&+|& ()|/ @, &&"			<< std::endl
		<< "     &+/(/&/&||/& /_/)_&/_&"		<< std::endl
		<< "  &() &+/&|()|/&+/ '%' & ()"		<< std::endl
		<< " &_+_&&_+ |& |&&/&__%_/_& &&"		<< std::endl
		<< "&&   && & &| &| /& & % ()& /&&"		<< std::endl
		<< "()&_---()&+&+|&&-&&--%---()~"		<< std::endl
		<< "            |||"					<< std::endl
		<< "            |||"					<< std::endl
		<< "            |||"					<< std::endl
		<< "            |||"					<< std::endl;

	out.close();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */