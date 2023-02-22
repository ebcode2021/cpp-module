#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		// signed(145), execute(137)
		std::cout << "----------------[ShrubberyCreationForm]----------------" << std::endl;
		
		AForm *form = new ShrubberyCreationForm("shru_form");
		std::cout << (*form);

		Bureaucrat success("success", 1);
		Bureaucrat sign_failed("sign_failed", 146);
		Bureaucrat execute_failed("execute_failed", 138);

		success.signForm(*form);
		success.executeForm(*form);

		sign_failed.signForm(*form);
		sign_failed.executeForm(*form);

		execute_failed.signForm(*form);
		execute_failed.executeForm(*form);
 
		delete form;
	}

	{
		// signed(72), execute(45)
		std::cout << "\n----------------[RobotomyRequestForm]----------------" << std::endl;
		
		AForm *form = new RobotomyRequestForm("robo_form");
		std::cout << (*form);

		Bureaucrat success("success", 1);
		Bureaucrat sign_failed("sign_failed", 74);
		Bureaucrat execute_failed("execute_failed", 46);

		success.signForm(*form);
		success.executeForm(*form);

		sign_failed.signForm(*form);
		sign_failed.executeForm(*form);

		execute_failed.signForm(*form);
		execute_failed.executeForm(*form);
 
		delete form;
	}

	{
		// signed(25), execute(5)
		std::cout << "\n----------------[PresidentialPardonForm]----------------" << std::endl;
		
		AForm *form = new PresidentialPardonForm("pres_form");
		std::cout << (*form);

		Bureaucrat success("success", 1);
		Bureaucrat sign_failed("sign_failed", 26);
		Bureaucrat execute_failed("execute_failed", 6);

		success.signForm(*form);
		success.executeForm(*form);

		sign_failed.signForm(*form);
		sign_failed.executeForm(*form);

		execute_failed.signForm(*form);
		execute_failed.executeForm(*form);
 
		delete form;
	}
	return (0);
}