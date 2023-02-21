#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main()
{
	{
		// signed(145), execute(137)
		std::cout << "----------------[ShrubberyCreationForm]----------------" << std::endl;
		try
		{
			Intern intern;

			AForm *form = intern.makeForm("shrubbery creation", "hi1");
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		// signed(72), execute(45)
		std::cout << "\n----------------[RobotomyRequestForm]----------------" << std::endl;
		try
		{
			Intern intern;

			AForm *form = intern.makeForm("robotomy request", "hi2");
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		// signed(25), execute(5)
		std::cout << "\n----------------[PresidentialPardonForm]----------------" << std::endl;
		try
		{
			Intern intern;

			AForm *form = intern.makeForm("presidential pardon", "hi3");
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		// signed(72), execute(45)
		std::cout << "\n----------------[nothing]----------------" << std::endl;
		try
		{
			Intern intern;

			AForm *form = intern.makeForm("nothing request", "eunson");
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}