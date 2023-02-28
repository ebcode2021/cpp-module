#include "easyfind.hpp"

int	main()
{
	/* [vector] */
	{
		std::vector<int> miniVector;

		miniVector.push_back(10);
		miniVector.push_back(20);
		miniVector.push_back(30);

		try
		{
			std::cout << "[vector]" << std::endl;
			for(std::vector<int>::iterator it = miniVector.begin(); it < miniVector.end(); it++)
				std::cout << *it << std::endl;

			int findValue = 10;
			easyfind(miniVector, findValue);
			std::cout << "vector find : " << findValue <<  std::endl;
			std::cout << "vector container's size : " << miniVector.size() << std::endl;

			miniVector.pop_back();
			findValue = 30;
			easyfind(miniVector, findValue);
			std::cout << "vector find : " << findValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "실패!" << std::endl;
		}
	}
	/* [list] */
	{
		std::list<double> miniList;
		std::list<double> miniList2;

		miniList.push_back(1.0);
		miniList.push_back(2.0);
		miniList.push_back(3.0);

		try
		{
			std::cout << "\n[list]" << std::endl;
			//std::list<double>::iterator	it;

			//it = miniList.begin();
			for (std::list<double>::iterator it = miniList.begin(); it != miniList.end(); it++)
				std::cout << *it << std::endl;

			double findValue = 1.0;
			easyfind(miniList, findValue);
			std::cout << "miniList find : " << findValue <<  std::endl;
			std::cout << "minilist container's size : " << miniList.size() << std::endl;
			
			miniList2.push_back(4.0);
			findValue = 4.0;
			easyfind(miniList2, findValue);
			std::cout << "miniList2 find : " << findValue <<  std::endl;
			std::cout << "miniList2 container's size : " << miniList2.size() << std::endl;

			miniList.splice(miniList.begin(), miniList2);
			std::cout << "minilist container's size : " << miniList.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "실패!\n" << std::endl;
		}
		

	}

	/* [deque] */
	{
		std::deque<float> miniFloat;

		miniFloat.push_front(1.0f);

		try
		{
			std::cout << "\n[deque]" << std::endl;
			
			int findValue = 1;
			easyfind(miniFloat, findValue);
			std::cout << "deque find : " << findValue <<  std::endl;
			std::cout << "deque container's size : " << miniFloat.size() << std::endl;

			miniFloat.pop_back();
			easyfind(miniFloat, findValue);
			std::cout << "vector find : " << findValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "실패!" << std::endl;
		}
	}
	return (0);
}