#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a;
	try
	{
		a.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// const std::string a = bu::get_name;

	// len = a.getPosX( ) + 1
	
	return (0);
}