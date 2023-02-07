#include <iostream>
#include <string>

void	megaphone(char *argv[])
{
	std::locale loc;
	while (*argv)
	{
		std::string str(*argv);
		for (int i = 0; i < str.length(); i++)
			std::cout << std::toupper(str[i], loc);
		argv++;
	}
	std::cout << std::endl;
}

int	main (int argc, char *argv[])
{
	if (argc > 1)
		megaphone(++argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
