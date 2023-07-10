# include "PmergeMe.hpp"

/* OCCF */
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe) : _list(pmergeMe._list), _deque(pmergeMe._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe)
{
	if (this != &pmergeMe)
	{
		this->_list = pmergeMe._list;
		this->_deque = pmergeMe._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(char *argv[])
{
	if (parseArguments(argv) == true) {
		run();
	}
	else {
		std::cout << "Error" << std::endl;
	}
}

/* method */
bool	PmergeMe::parseArguments(char *argv[]) {

	std::list<std::string>::iterator it;

	for (size_t i = 0; argv[i] != NULL; i++)
	{
		std::string	argument(argv[1]);
		std::list<std::string>	numbers;
		split(argument, ' ', numbers);

		for (it = numbers.begin(); it != numbers.end(); it++) {
			int number = stoi(*it);
			this->_deque.push_back(number);
			this->_list.push_back(number);
		}
	}
}

void	PmergeMe::run()
{
	clock_t				startTime;
	clock_t				dequeTime;
	clock_t				listTime;

	startTime = clock();
	// sort(this->_deque)
	dequeTime = clock() - startTime;

	startTime = clock();
	// sort(this->_list);
	listTime = clock() - startTime;

	printSortChange();
	printTimeStamp(this->_list.size(), dequeTime, listTime);
}

void split(const std::string& str, char delimiter, std::list<std::string>& tokens) {
	
	std::istringstream tokenStream(str);
	std::string token;

	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
}

int	stoi(std::string& str)
{
	long long	result = 0;

	if (str[0] == '-')
		printErrorWithExit();

	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];

		if (i == 0 && c == '+')
			continue;
		if (c < '0' || c > '9')
			printErrorWithExit();
		result = result * 10 + (c - '0');
		if (result > 2147483647)
			printErrorWithExit();
	}
	return (result);
}

/* print method */
void	PmergeMe::printTimeStamp(size_t totalCnt, clock_t dequeTime, clock_t listTime)
{
	std::cout << "Time to process a range of " << totalCnt << " elements with std::deque : " << dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of " << totalCnt << " elements with std::list : " << listTime << " us" << std::endl;
}

void	PmergeMe::printSortChange()
{
	std::list<int>::iterator	it;
	std::list<int>				copyList = this->_list;
	copyList.sort();

	std::cout << "Before: ";

	for (it = this->_list.begin(); it != this->_list.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (it = copyList.begin(); it != copyList.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void	printErrorWithExit() {
	std::cout << "Error" << std::endl;
	exit(1);
}