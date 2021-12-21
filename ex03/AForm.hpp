/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:56:06 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 12:56:14 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm( std::string name, int sign_grade, int exec_grade, std::string target);
		virtual ~AForm();

		AForm &			operator=( AForm const & rhs );
		void			setSigned(bool s);
		bool			getSigned() const;
		std::string		getName() const;
		std::string		getTarget() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		void			beSigned(Bureaucrat const & bureaucrat);
		void			exec_paperwork_check(Bureaucrat const & bureaucrat) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:

		bool				_signed;
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		const std::string	_target;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */