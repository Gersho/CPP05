/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:55:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/21 12:55:41 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

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

	private:

		bool				_signed;
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */