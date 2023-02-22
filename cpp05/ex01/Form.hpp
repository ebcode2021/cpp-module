#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class	Form
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
		Form& operator=(const Form&);

	public :
		// OCCF
		Form();
		Form(const Form&);
		~Form();

		// parameter consturctor
		Form(std::string, bool, int, const int);

		// getter
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		bool	beSigned(Bureaucrat&);
};

std::ostream& operator << (std::ostream &out, const Form& form);

#endif