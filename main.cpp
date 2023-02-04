#include "test.hpp"

using namespace std;

int main()
{
	// test teat;
	// std::string a;
	// // std::cout << test::a << std::endl;
	// // std::cout << teat.a << std::endl;

	// std::cout << a.length() << std::endl;
	// std::cout << strlen(a.c_str()) << std::endl;
	// std::cout << test::strlen(a) << std::endl;

	char str[5] = {'a', 'b', 'c', 'd', 0};

	std::string a("abcd");
	std::string b("efg");
	std::string c(b);
	std::cout << b << "\n" << c << "\n" <<std::endl;
	b = "abcd";
	std::cout << b << "\n" << c << "\n" <<std::endl;
	a = b;

	test test1(str);
	test test2(test1);
	test test3;
	test3 = test2;
	std::cout << test1.str << "\n" << test2.str << "\n" << test3.str << std::endl;
	str[0] = 'f';
	std::cout << test1.str << "\n" << test2.str << "\n" << test3.str << std::endl;
}