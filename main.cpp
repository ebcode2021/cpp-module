#include "test.hpp"

using namespace std;

int main()
{
	test teat;
	std::string a;
	// std::cout << test::a << std::endl;
	// std::cout << teat.a << std::endl;

	std::cout << a.length() << std::endl;
	std::cout << strlen(a.c_str()) << std::endl;
	std::cout << test::strlen(a) << std::endl;
}