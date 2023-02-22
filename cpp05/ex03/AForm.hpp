#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	AForm
{
	private :
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
		AForm& operator=(const AForm&);

	public :
		// OCCF
		AForm();
		AForm(const AForm&);
		virtual ~AForm();

		// parameter consturctor
		AForm(std::string, std::string, bool, int, const int);
		AForm(std::string);

		// getter
		std::string	getName() const;
		std::string getTarget() const;
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

		// member function
		bool	beSigned(Bureaucrat&);

		// pure virtual function
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator << (std::ostream &out, const AForm& form);

#endif