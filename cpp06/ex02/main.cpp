#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate()
{
	srand(time(NULL));
	int	random_value = rand() % 3;

	if (random_value == 0)
		return (new A());
	else if (random_value == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B!" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C!" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "A!!!" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "B!!!" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "C!!!" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	return (0);
}
