#include "Bureaucrat.hpp"

// const char* Bureaucrat::GradeTooHighException::what() const noexcept
// {
// 	return "TOO HIGH!!!!!";
// }

// const char*	Bureaucrat::GradeTooLowException::what() const noexcept
// {
// 	return "TOO LOW!!!!!";
// }

const char* GradeTooHighException::what() const throw()
{
	return "hi";
}
void	Bureaucrat::increaseGrade()
{
	throw GradeTooHighException();
	this->_grade -= 1;
}