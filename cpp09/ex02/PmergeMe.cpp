# include "PmergeMe.hpp"

/* delare function */
template<typename Container>
void	merge(Container& left, Container& right, Container& sequence);
template<typename Container>
void	mergeInsertionSort(Container& sequence);
int		stoi(std::string& str);
void 	split(const std::string& str, char delimiter, std::list<std::string>& tokens);
void	printErrorWithExit();


/* OCCF */
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe) : _deque(pmergeMe._deque), _list(pmergeMe._list), _origin(pmergeMe._origin) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe)
{
	if (this != &pmergeMe)
	{
		this->_deque = pmergeMe._deque;
		this->_list = pmergeMe._list;
		this->_origin = pmergeMe._origin;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(char *argv[])
{
	parseArguments(argv);
	run();
}

/* method */
void	PmergeMe::parseArguments(char *argv[]) {

	std::list<std::string>::iterator it;

	for (size_t i = 0; argv[i] != NULL; i++)
	{
		std::string	argument(argv[i]);
		std::list<std::string>	numbers;
		split(argument, ' ', numbers);

		for (it = numbers.begin(); it != numbers.end(); it++) {
			int number = stoi(*it);
			this->_deque.push_back(number);
			this->_list.push_back(number);
			this->_origin.push_back(number);
		}
	}
}

void	PmergeMe::run()
{
	clock_t				startTime;
	clock_t				dequeTime;
	clock_t				listTime;

	startTime = clock();
	mergeInsertionSort(this->_deque);
	dequeTime = clock() - startTime;

	startTime = clock();
	mergeInsertionSort(this->_list);
	listTime = clock() - startTime;

	printSortChange();
	printTimeStamp(dequeTime, listTime);
}

template<typename Container>
void	merge(Container& left, Container& right, Container& sequence)
{
	typename Container::iterator itLeft = left.begin();
	typename Container::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < * itRight) {
			sequence.push_back(*itLeft);
			++itLeft;
		}
		else {
			sequence.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end()) {
		sequence.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end()) {
		sequence.push_back(*itRight);
		++itRight;
	}
}

template<typename Container>
void	mergeInsertionSort(Container& sequence)
{
	typename Container::iterator it = sequence.begin();
	std::advance(it, sequence.size() / 2);

	if (sequence.size() <= 1)
		return ;
	Container left(sequence.begin(), it);
	Container right(it, sequence.end());

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	sequence.clear();
	merge(left, right, sequence);
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
	
	if (str[0] == '-') {
		printErrorWithExit();
	}

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
void	PmergeMe::printTimeStamp(clock_t dequeTime, clock_t listTime)
{
	std::cout << "Time to process a range of " << this->_origin.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_origin.size() << " elements with std::list : " << listTime << " us" << std::endl;
}

void	PmergeMe::printSortChange()
{
	std::list<int>::iterator	it;
	std::list<int>				copyList = this->_origin;
	copyList.sort();

	std::cout << "Before: ";

	for (it = this->_origin.begin(); it != this->_origin.end(); it++)
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