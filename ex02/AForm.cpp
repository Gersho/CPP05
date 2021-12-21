/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:56:03 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 12:57:23 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _signed(false), _name("A38 pass"), _sign_grade(1), _exec_grade(1)
{
}

AForm::AForm( const AForm & src ): _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	_signed = getSigned();
}

AForm::AForm( std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	_signed = false;
	try 
	{
		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw AForm::GradeTooLowException();
		else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw AForm::GradeTooHighException();
	}
	catch (AForm::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		this->~AForm();
		return;
	}
	catch (AForm::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		this->~AForm();
		return;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "Form: " << i.getName() << std::endl
	<< "sign grade: " << i.getSignGrade() << std::endl
	<< "exec grade: " << i.getExecGrade() << std::endl
	<< "signed: ";
	if (i.getSigned())
		o << "yes" << std::endl;
	else
		o << "no" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())	
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool	AForm::getSigned() const
{
	return _signed;
}

std::string	AForm::getName() const
{
	return _name;
}

int	AForm::getSignGrade() const
{
	return _sign_grade;
}

int	AForm::getExecGrade() const
{
	return _exec_grade;
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ************************************************************************** */