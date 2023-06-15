# include "BitcoinExchange.hpp"

static std::vector<std::string> split(const std::string& str, const std::string& delims);

// OCCF
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btcExchange)
{
	this->_data = btcExchange._data;
	this->_csvFile = btcExchange._csvFile;
}

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

// constructor
BitcoinExchange::BitcoinExchange(char *inputFile) : _csvFile("data.csv")
{
	if (initDataFromFile() == true)
		run(std::string(inputFile));
}

// method
bool	BitcoinExchange::initDataFromFile()
{
	std::ifstream	file(this->_csvFile);

	if (file.is_open())
	{
		std::string	line;
		float		exchange;

		std::getline(file, line);

		while (std::getline(file, line))
		{
			std::string			date, exchange_rate;
			std::istringstream	iss(line);
			
			std::getline(iss, date, ',');
			std::getline(iss, exchange_rate, ',');

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

void	BitcoinExchange::run(const std::string& input)
{
	std::ifstream	file(input);

	if (file.is_open())
	{
		std::string	line;

		std::getline(file, line);
		while (std::getline(file, line))
		{
			float value;
			std::string	date, count;

			std::istringstream	iss(line);
			
			std::getline(iss, date, '|');
			std::getline(iss, count, '|');

			try {
				value = std::stof(count);
			}
			catch (std::exception &ex) {
				printError("value is not convert to number.");
				continue ;
			}

			if (checkDataFormat(date, value) == true)
				printCalculate(date, value);
		}
	}
	else
		printError("file is not open.");
}

bool	BitcoinExchange::checkDataFormat(const std::string& date, const float count)
{
	// check-date
	std::vector<std::string>	splittedDate = split(date, "-");

	int	year = std::atoi(splittedDate[0].c_str());
	int	month = std::atoi(splittedDate[1].c_str());
	int	day = std::atoi(splittedDate[2].c_str());

	if ((year >= 2000 && year <= 2023) == false || \
		((month % 2 == 0 && day >= 1 && day <= 31) == false && \
		(month % 2 == 1 && day >= 1 && day <= 30) == false))
	{
		printError("bad input => " + date);
		return (false);
	}

	// check-count
	if ((count >= 0 && count <= 1000) == false)
	{
		if (count < 0)
			printError("not a positive number.");
		else
			printError("too large a number.");
		return (false);
	}
	return (true);
}

int	BitcoinExchange::convertDateToDay(const std::string& date)
{
	std::vector<std::string>	splittedDate = split(date, "-");
	
	int	year = std::atoi(splittedDate[0].c_str());
	int	month = std::atoi(splittedDate[1].c_str());
	int	day = std::atoi(splittedDate[2].c_str());

	return (year * 365 + month * 30 + day);
}
std::string	BitcoinExchange::findPreviousDate(const std::string& date)
{
	std::string		previousDate;
	int				currentDay = convertDateToDay(date);

	//std::cout << "들어간 데이트 : " << date << std::endl;
	std::map<std::string, float>::const_iterator it;

	for (it = this->_data.begin(); it != this->_data.end(); it++)
	{
		if (convertDateToDay((*it).first) < currentDay)
		{
			//std::cout << "이전 : " << convertDateToDay((*it).first) << " | 지금 : " << currentDay << std::endl;
			previousDate = (*it).first;
		}
		else
		{
			//exit(0);
			break ;
		}
	}
	return (previousDate);
}

bool	BitcoinExchange::isExchangeValue(const std::string& date)
{
	std::map<std::string, float>::const_iterator it = this->_data.find(date);

	if (it != this->_data.end())
		return (true);
	return (false);
}

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
	{
		printResult(date, this->_data[date], count);
	}
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
