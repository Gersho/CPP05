/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:15:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 15:43:18 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name("Bob"), _grade(75)
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src.getName())
{	
	try
	{
		if (src.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (src.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade = src.getGrade();
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		_grade = 1;
		return;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		_grade = 150;
		return;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		_grade = 1;
		return;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		_grade = 150;
		return;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
	
void	Bureaucrat::promote()
{
	try
	{
		if (this->getGrade() == 1)
			throw Bureaucrat::GradeTooHighException();
		else
		{
			std::cout << this->getName() << " is promoted, going from grade " << this->getGrade();
			_grade--;
			std::cout << " to grade " << this->getGrade() << std::endl;;
		}
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
}

void	Bureaucrat::demote()
{
	try
	{
		if (this->getGrade() == 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			std::cout << this->getName() << " is demoted, going from grade " << this->getGrade();
			_grade++;
			std::cout << " to grade " << this->getGrade() << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
}

void	Bureaucrat::signForm( AForm & form)
{
	if (form.getSigned())
	{
		std::cout << "Form " << form.getName() << " is already signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << "." << std::endl;
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}


void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.exec_paperwork_check(*this);
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << "." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ************************************************************************** */