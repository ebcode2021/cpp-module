#include "ShrubberyCreationForm.hpp"
#include <fstream>

// OCCF
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "none", 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm :: default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : AForm(s.getName(), s.getTarget(), s.getSigned(), s.getSignedGrade(), s.getExecuteGrade())
{
		std::cout << "ShrubberyCreationForm :: copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
	(void)shrubberyCreationForm;
	std::cout << "ShrubberyCreationForm :: copy assignment operator" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm :: destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 0, 145, 137)
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream	file(this->getTarget() + "_shrubbery");
	file << "               ,@@@@@@@,\n"
                "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                "       |o|        | |         | |\n"
                "       |.|        | |         | |\n"
                "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	file.close();
}