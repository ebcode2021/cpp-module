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

int main()
// {
// 	Fixed b(a); //복사생성(주소값)
// 	const Fixed a(b);

	// a = b;
	// b->dkfjkl = "asdlfkjkldf";
	// Fixed c;
	// c = Fixed(b); // 할당대입.
	// b = a; // 할당대입
	int a = 5;
	a = 6;
	int a = 1;
	char a = (char)a;
	//a = static_cast< : 내가 아는 그거.
	//interpret_cast<> : 주소변환
	//dynamic_cast<> 동적으로 작동은 안하고. 그냥..typeinfo를 사실 확인하는게 맞는데, 98식으로 ? 뇌피셜 ㅎㅎ
	int a; 		부모
	int b;		자식
	a = b;
	b = a;
	if (dynamic_cast<a>(b) == NULL)

}