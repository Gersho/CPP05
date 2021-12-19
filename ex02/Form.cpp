#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _signed(false), _name("default Form"), _sign_grade(75), _exec_grade(75)
{
}

Form::Form( const Form & src ): _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	_signed = getSigned();
}

Form::Form( std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	_signed = false;
	try 
	{
		if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
			throw Form::GradeTooLowException();
		else if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		this->~Form();
		return;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		this->~Form();
		return;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
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

void		Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())	
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool	Form::getSigned() const
{
	return _signed;
}

std::string	Form::getName() const
{
	return _name;
}

int	Form::getSignGrade() const
{
	return _sign_grade;
}

int	Form::getExecGrade() const
{
	return _exec_grade;
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ************************************************************************** */