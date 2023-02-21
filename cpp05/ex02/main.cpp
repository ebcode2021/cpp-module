#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout << "----------------[test1]----------------" << std::endl;
		try
		{
			Form form;
			Bureaucrat bureaucrat("eunson", 1);
			bureaucrat.signForm(form);
			std::cout << "별 문제 없으면 보이는 메시지" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n----------------[test2]----------------" << std::endl;
		try
		{
			Form form("low_form", 0, 150, 150);
			Bureaucrat bureaucrat("eunson", 100);
			std::cout << "\n- " << bureaucrat.getName() << "의 정보" << std::endl;
			std::cout << bureaucrat;
			std::cout << "\n- 사인 전 " << form.getName() << "의 정보" << std::endl;
			std::cout << form;
			bureaucrat.signForm(form);
			std::cout << "\n- 사인 후" << form.getName() << "의 정보" << std::endl;
			std::cout << form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n----------------[test3]----------------" << std::endl;
		try
		{
			Form form;
			Bureaucrat bureaucrat("eunson", 2);
			bureaucrat.signForm(form);
			std::cout << form;
			std::cout << "\n- 등급 올려보기" << std::endl;
			bureaucrat.increaseGrade();
			bureaucrat.signForm(form);
			std::cout << form;
			std::cout << "\n- 이미 사인한 서류에 재접근하기" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}