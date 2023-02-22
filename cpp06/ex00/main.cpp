#include <iostream>
#include "Converter.hpp"

int	main(int argc, char*argv[])
{
	if (argc == 2)
		Converter::convert(argv[1]);
	return (0);
}