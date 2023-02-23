#include <iostream>
#include "Array.hpp"

int	main()
{
	// default 생성
	std::cout << "- Array<int> a" << std::endl;
	Array<int> a;
	std::cout << a;

	std::cout << "- Array<char> b" << std::endl;
	Array<char> b(5);
	char input = 'a';
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = input++;
	std::cout << b;

	std::cout << "- Array<int> c" << std::endl;
	Array<int> c(5);
	for (unsigned int i = 0; i < c.size(); i++)
		c[i] = i + 1;
	std::cout << c;
	
	std::cout << "- Array<int> newC" << std::endl;
	Array<int> newC(c);
	newC[0] = 42;
	std::cout << newC;

	std::cout << "- c가 바뀌었나?" << std::endl;
	std::cout << c;

	std::cout << "- Array<int> newnewC" << std::endl;
	newC = c;
	std::cout << newC;
	// error situation
	try
	{
		std::cout << "- Array<double> d" << std::endl;
		Array<double> d(4);
		d[-1] = 0;
		std::cout << d;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "- Array<double> e" << std::endl;
		Array<double> e(4);
		e[6] = 0;
		std::cout << e;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}