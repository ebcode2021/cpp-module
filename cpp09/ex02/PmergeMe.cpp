# include "PmergeMe.hpp"

/* OCCF */
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe)
{
	this->_deque = pmergeMe._deque;
	this->_vector = pmergeMe._vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe)
{
	if (this != &pmergeMe)
	{
		this->_deque = pmergeMe._deque;
		this->_vector = pmergeMe._vector;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(char *argv[])
{
	// 여기서 멤버변수 초기화
	// stoi 만들어야할듯?
	run();
}

/* method */
void	PmergeMe::run()
{
	std::deque<int>		sortedDeque;
	std::vector<int>	sortedVector;
	clock_t				startTime;
	clock_t				dequeTime;
	clock_t				vectorTime;

	startTime = clock();
	// sort(this->_deque)
	dequeTime = clock() - startTime;

	startTime = clock();
	// sort(this->_vector);
	vectorTime = clock() - startTime;

	printResult(sortedDeque, dequeTime, vectorTime);
}

/* print method */
void	PmergeMe::printResult(std::deque<int> sortedList, clock_t firstTime, clock_t secondTime)
{
	std::cout << "Before: ";
	printList(); //template method
	std::cout << "After: ";
	printList(); //
	std::cout << "Time to process a range of 3000 elements with std::deque : " << firstTime << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::vector : " << secondTime << std::endl;
}

void	PmergeMe::printList()
{
	std::deque<int>::iterator it;

	for (it = this->_deque.begin(); it != this->_deque.end(); it++)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}