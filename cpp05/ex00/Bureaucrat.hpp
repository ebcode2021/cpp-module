#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private :
		const std::string	name;
		int					grade;

	public :
		void		GradeTooHighException();
		void		GradeTooLowException();

		std::string	getName() const;
		int			getGrade() const;

		
};

#endif