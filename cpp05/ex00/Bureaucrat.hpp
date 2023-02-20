#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
		Bureaucrat& operator=(const Bureaucrat&);

	public :
		// OCCF
		Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();

		// parameter consturctor
		Bureaucrat(std::string, int);

		std::string	getName() const;
		int			getGrade() const;

		void		increaseGrade();
		void		decreaseGrade();

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream &out, const Bureaucrat& bureaucrat);

#endif