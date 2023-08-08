# include "BitcoinExchange.hpp"

/* delare static function */
static std::vector<std::string> split(const std::string& str, const std::string& delims);
static	int	calculateTotalDay(int year, int month, int day);
static	int	isLeapYear(int year);

/* OCCF */
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btcExchange) : _data(btcExchange._data), _csvFile(btcExchange._csvFile) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btcExchange)
{
	if (this != &btcExchange)
	{
		this->_data = btcExchange._data;
		this->_csvFile = btcExchange._csvFile;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}


/* constructor */
BitcoinExchange::BitcoinExchange(char *inputFile) : _csvFile("data.csv")
{
	if (initDataFromFile() == true)
		run(std::string(inputFile));
}

// method
void	BitcoinExchange::run(const std::string& input)
{
	std::ifstream	file(input);

	if (file.is_open())
	{
		std::string	line;

		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::vector<std::string>	splittedLine = split(line, "| ");
			if (splittedLine.size() == 0)
				continue ;
			else if (splittedLine.size() != 2)
			{
				printError("bad input => " + line);
				continue ;
			}

			std::string	date = splittedLine[0];
			std::string	value = splittedLine[1];
			
			if (checkDateFormat(date) == true)
			{
				float newValue;

				try {
					newValue = std::stof(value);
				}
				catch (std::exception &ex) {
					printError("value is not convert to number.");
					continue ;
				}

				if (checkValueFormat(newValue) == true)
					printCalculate(date, newValue);
			}
		}
	}
	else
		printError("file is not open.");
}

bool	BitcoinExchange::initDataFromFile()
{
	std::ifstream	file(this->_csvFile.c_str());

	if (file.is_open())
	{
		std::string	line;
		float		exchange;

		std::getline(file, line);

		while (std::getline(file, line))
		{
			std::vector<std::string>	splittedData = split(line, ",");
			std::string	date = splittedData[0];
			std::string	exchange_rate = splittedData[1];

			try {
				exchange = std::stof(exchange_rate);
			}
			catch (const std::exception& e) {
				printError("check the status of the csv file.");
				exit(1);
			}
			this->_data.insert(std::make_pair(date, exchange));
		}
		return (true);
	}
	printError("file is not open.");
	return (false);
}

int	BitcoinExchange::convertDateToDay(const std::string& date)
{
	std::vector<std::string>	splittedDate = split(date, "-");
	
	int	year = std::atoi(splittedDate[0].c_str());
	int	month = std::atoi(splittedDate[1].c_str());
	int	day = std::atoi(splittedDate[2].c_str());

	return (calculateTotalDay(year, month, day));
}

std::string	BitcoinExchange::findPreviousDate(const std::string& date)
{
	std::string		previousDate;
	int				currentDay = convertDateToDay(date);

	std::map<std::string, float>::const_iterator it;

	for (it = this->_data.begin(); it != this->_data.end(); it++)
	{
		if (convertDateToDay((*it).first) < currentDay)
			previousDate = (*it).first;
		else
			break ;
	}
	return (previousDate);
}

/* boolean method */
bool	BitcoinExchange::isExchangeValue(const std::string& date)
{
	std::map<std::string, float>::const_iterator it = this->_data.find(date);

	if (it != this->_data.end())
		return (true);
	return (false);
}

bool	BitcoinExchange::checkDateFormat(const std::string& date)
{
	bool	returnFlag = true;
	std::vector<std::string>	splittedDate = split(date, "-");

	if (splittedDate.size() != 3)
	{
		printError("bad input => " + date);
		return (false);
	}
	
	int	year = std::atoi(splittedDate[0].c_str());
	int	month = std::atoi(splittedDate[1].c_str());
	int	day = std::atoi(splittedDate[2].c_str());

	if ((year < 2000 || year > 2023) == true)
		returnFlag = false;
	if ((month < 1 || month > 12) == true)
		returnFlag = false;
	if (day < 1)
		returnFlag = false;
	if ((month < 8 && month % 2 == 1) || month == 8 || (month > 8 && month % 2 == 0))
	{
		if (day > 31)
			returnFlag = false;
	}
	else if (month == 2)
	{
		if (isLeapYear(year) == true)
		{
			if (day > 29)
				returnFlag = false;
		}
		else
		{
			if (day > 28)
				returnFlag = false;
		}
	}
	else
	{
		if (day > 30)
			returnFlag = false;
	}
	if (returnFlag == true)
		return (true);
	else
	{
		printError("bad input => " + date);
		return (false);
	}
}

bool	BitcoinExchange::checkValueFormat(const float value)
{
	if ((value >= 0 && value <= 1000) == false)
	{
		if (value < 0)
			printError("not a positive number.");
		else
			printError("too large a number.");
		return (false);
	}
	return (true);
}

/* print method */
void	BitcoinExchange::printCalculate(const std::string& date, const float count)
{
	std::string	newDate;

	if (isExchangeValue(date) == false)
	{
		newDate = findPreviousDate(date);
		if (newDate.empty() == false)
			printResult(date, this->_data[newDate], count);
		else
			printError("can not find btc's previous data!");
	}
	else
		printResult(date, this->_data[date], count);
}

void	BitcoinExchange::printResult(const std::string& date, const float value, const float count)
{
	std::cout << date << " => " << count << " = " << count * value << std::endl;
}

// print method
void	BitcoinExchange::printError(const std::string& message)
{
	std::cerr << "Error: " << message << std::endl;
}

/* static method */
static	int	calculateTotalDay(int year, int month, int day)
{
	int totalDay = year * 365 + day;

	int	startMonth = 1;
	while (startMonth <= month)
	{
		if ((startMonth < 8 && startMonth % 2 == 1) || startMonth == 8 || (startMonth > 8 && startMonth % 2 == 0))
			totalDay += 31;
		else if (startMonth == 2)
		{
			if (isLeapYear(year) == true)
				totalDay += 29;
			else
				totalDay += 28;
		}
		else
			totalDay += 30;
		startMonth += 1;
	}
	return (totalDay);
}

static std::vector<std::string> split(const std::string& str, const std::string& delims)
{
	std::vector<std::string>	tokens;
	size_t	start = 0, end = 0;

	while ((end = str.find_first_of(delims, start)) != std::string::npos) {
		if (end != start) {
			tokens.push_back(str.substr(start, end - start));
		}
		start = end + 1;
	}
	if (start < str.length())
		tokens.push_back(str.substr(start));
	return (tokens);
}

static	int	isLeapYear(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (true);
	return (false);
}