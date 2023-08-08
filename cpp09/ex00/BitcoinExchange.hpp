#ifndef BTC_EXCHANGE_HPP
# define BTC_EXCHANGE_HPP

# include <stdlib.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>

class	BitcoinExchange
{
	private :
		std::map<std::string, float>	_data;
		std::string						_csvFile;

	public :
		// OCCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		// constructor
		BitcoinExchange(char *);

		// method
		void		run(const std::string&);
		bool		initDataFromFile();
		int			convertDateToDay(const std::string&);
		std::string	findPreviousDate(const std::string&);

		// boolean method
		bool		isExchangeValue(const std::string&);
		bool		checkDateFormat(const std::string&);
		bool		checkValueFormat(const float);


		// print method
		void		printError(const std::string&);
		void		printCalculate(const std::string&, const float);
		void		printResult(const std::string&, const float value, const float);
};
#endif