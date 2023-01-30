#include <iostream>

void	deadSignalCheck(void)
{
	if (std::cin.eof())
		exit (1);
}