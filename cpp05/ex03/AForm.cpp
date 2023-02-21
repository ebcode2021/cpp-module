#include "AForm.hpp"
#include "Bureaucrat.hpp"

// OCCF
AForm::AForm() : _name("default"), _target("none"), _signed(false), _signed_grade(1), _execute_grade(1)
{
	std::cout << "AForm :: default constructor" << std::endl;
}

AForm::AForm(const AForm& form) : _name(form._name), _target(form._target), _signed(form._signed), _signed_grade(form._signed_grade), _execute_grade(form._execute_grade)
{
	std::cout << "AForm :: copy constructor" << std::endl;
};

AForm& AForm::operator=(const AForm& form)
{
	(void)form;
	std::cout << "AForm :: copy assignment operator" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm :: destructor" << std::endl;
}

AForm::AForm(std::string name, std::string target, bool sign, int signed_grade, const int execute_grade) : 
	_name(name), _target(target), _signed(sign), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	if (signed_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (signed_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat :: parameter constructor" << std::endl;
}

AForm::AForm(std::string target) : _name("default"), _target(target), _signed(false), _signed_grade(1), _execute_grade(1){}

// getter
std::string AForm::getName() const
{
	return (this->_name);
}

std::string AForm::getTarget() const
{
	return (this->_target);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignedGrade() const
{
	return (this->_signed_grade);
}

int AForm::getExecuteGrade() const
{
	return (this->_execute_grade);
}

// exception
const char* AForm::GradeTooHighException::what() const throw()
{
	return "TOO HIGH!!!!!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "TOO LOW!!!!!";
}

// member function
bool AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_signed)
		return true;
	if (bureaucrat.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	else
		this->_signed = true;
	return false;
}

std::ostream& operator << (std::ostream &out, const AForm& form)
{
	out << form.getName() << ", form signed " 
		<< form.getSigned() << ", form target "
		<< form.getTarget() << ", form signeed grade "
		<< form.getSignedGrade() << ", form executed grade "
		<< form.getExecuteGrade() << std::endl;
	return (out);
}