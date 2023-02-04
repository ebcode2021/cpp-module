#include "test.hpp"

test::test() {
	this->str = NULL;
}

test::test(char *a)
{
	this->str = a;
}

test::test(const test& origin)
{
	this->str = strdup(origin.str);
}

test&	test::operator=(const test& origin)
{
	this->str = origin.str;
	return *this;
}
