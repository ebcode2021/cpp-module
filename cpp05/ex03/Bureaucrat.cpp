#include "Bureaucrat.hpp"
#include "AForm.hpp"

// OCCF
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{
	std::cout << "Bureaucrat :: default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade)
{
	std::cout << "Bureaucrat :: copy constructor" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	(void)bureaucrat;
	std::cout << "Bureaucrat :: copy assignment operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat :: destructor" << std::endl;
}

// parameter constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat :: parameter constructor" << std::endl;
}

// exception
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TOO HIGH!!!!!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TOO LOW!!!!!";
}

// getter
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

// member functions
void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (form.beSigned(*this))
			std::cout << this->_name << " couldn't sign " << form.getName() \
				<< " because already signed" << std::endl;
		else
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if(form.getSigned() == true)
		{
			form.execute(*this);
			std::cout << this->_name << " executed " << form.getName() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " didn't executed." << std::endl;
	}
}

std::ostream& operator << (std::ostream &out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " 
		<< bureaucrat.getGrade() << std::endl;
	return (out);
}