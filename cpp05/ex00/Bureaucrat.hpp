#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;

	public :
		// OCCF
		//Bureaucrat();
		//Bureaucrat(const Bureaucrat&);
		//Bureaucrat& operator=(const Bureaucrat&);
		////~Bureaucrat();

		//Bureaucrat(std::string);

		//std::string	getName() const;
		//int			getGrade() const;

		void		increaseGrade();
	//	void		decreaseGrade();

		// class GradeTooHighException : public std::exception
		// {
		// 	const char* what() const noexcept;
		// };

		// class GradeTooLowException : public std::exception
		// {
		// 	const char* what() const noexcept
		// };
};

#endif