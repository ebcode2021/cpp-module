# include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		BitcoinExchange btc(argv[1]);
	else
		std::cerr << "Error: could not open file." << std::endl;
	return (0);
}