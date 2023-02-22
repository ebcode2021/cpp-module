#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// OCCF
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "none", 0, 72, 45)
{
	std::cout << "RobotomyRequestForm :: default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : AForm(s.getName(), s.getTarget(), s.getSigned(), s.getSignedGrade(), s.getExecuteGrade())
{
		std::cout << "RobotomyRequestForm :: copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
	(void)robotomyRequestForm;
	std::cout << "RobotomyRequestForm :: copy assignment operator" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm :: destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 0, 72, 45)
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "driiiiiiiii" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized succesful" << std::endl;
	else
		std::cout << this->getTarget() << "has been rbotomized failure!" << std::endl;
}