#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "----------------[test1]----------------" << std::endl;
		try
		{
			Bureaucrat a("a_student", 1);
			std::cout << a << std::endl;
			Bureaucrat b("b_student", 150);
			std::cout << b << std::endl;
			std::cout << "별 문제 없으면 보이는 메시지" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "----------------[test2]----------------" << std::endl;
		try
		{
			Bureaucrat a("1등 학생", 1);
			a.increaseGrade();
			std::cout << "별 문제 없으면 보이는 메시지" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "문제 있으면 보이는 메시지" << std::endl;
		}
	}

	{
		std::cout << "----------------[test3]----------------" << std::endl;
		try
		{
			Bureaucrat a("꼴등 학생", 150);
			a.decreaseGrade();
			std::cout << "별 문제 없으면 보이는 메시지" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "문제 있으면 보이는 메시지" << std::endl;
		}
	}
	return (0);
}