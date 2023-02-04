# include <iostream>

class test
{
	public :
		test();
		test(char *a);
		test(const test&);
		static int	strlen(std::string str)
		{
			return str.length() + 1;
		}
		test&	operator=(const test&);
	public :
		int a;
		char *str;

};