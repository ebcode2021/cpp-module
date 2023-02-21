#include "Form.hpp"
#include "Bureaucrat.hpp"

// OCCF
Form::Form() : _name("default"), _signed(0), _signed_grade(1), _execute_grade(1)
{
	std::cout << "Form :: default constructor" << std::endl;
}

Form::Form(const Form& form) : _name(form._name),  _signed(form._signed), _signed_grade(form._signed_grade), _execute_grade(form._execute_grade)
{
	std::cout << "Form :: copy constructor" << std::endl;
};

Form& Form::operator=(const Form& form)
{
	(void)form;
	std::cout << "Form :: copy assignment operator" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form :: destructor" << std::endl;
}

Form::Form(std::string name, bool sign, int signed_grade, const int execute_grade) : 
	_name(name),  _signed(sign), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	if (signed_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (signed_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat :: parameter constructor" << std::endl;
}

// getter
std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignedGrade() const
{
	return (this->_signed_grade);
}

int Form::getExecuteGrade() const
{
	return (this->_execute_grade);
}

// exception
const char* Form::GradeTooHighException::what() const throw()
{
	return "TOO HIGH!!!!!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "TOO LOW!!!!!";
}

// member function
bool Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_signed)
		return true;
	if (bureaucrat.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	else
		this->_signed = true;
	return false;
}

std::ostream& operator << (std::ostream &out, const Form& form)
{
	out << form.getName() << ", form signed " 
		<< form.getSigned() << ", form signed grade "
		<< form.getSignedGrade() << ", form executed grade "
		<< form.getExecuteGrade() << std::endl;
	return (out);
}