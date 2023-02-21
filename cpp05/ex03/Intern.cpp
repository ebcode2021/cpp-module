#include "Intern.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// OCCF
Intern::Intern()
{
	std::cout << "Intern :: default constructor" << std::endl;
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
	std::cout << "Intern :: copy constructor" << std::endl;
};

Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	std::cout << "Intern :: copy assignment operator" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern :: destructor" << std::endl;
}

AForm*	Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRoboto(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

// exception
const char* Intern::FormNotFoundException::what() const throw()
{
	return "Not Found Form!!!!!!!!!!\n";
}

// member func
AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string levels[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*pointer_func[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRoboto,
		&Intern::createPresident
	};

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(levels[i]) == 0)
			return (this->*pointer_func[i])(target);
	}
	throw FormNotFoundException();
}
