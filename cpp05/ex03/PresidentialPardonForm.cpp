#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cstdlib>

// OCCF
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "none", 0, 25, 5)
{
	std::cout << "PresidentialPardonForm :: default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : AForm(s.getName(), s.getTarget(), s.getSigned(), s.getSignedGrade(), s.getExecuteGrade())
{
		std::cout << "PresidentialPardonForm :: copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm)
{
	(void)presidentialPardonForm;
	std::cout << "PresidentialPardonForm :: copy assignment operator" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm :: destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 0, 25, 5)
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}