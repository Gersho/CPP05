#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form( std::string name, int sign_grade, int exec_grade);
		~Form();

		Form &		operator=( Form const & rhs );
		bool		getSigned() const;
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat & bureaucrat);

	private:

		bool				_signed;
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */