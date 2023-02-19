#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void	leaks()
// {
// 	system("leaks a.out");
// }

int	main()
{
	// atexit(leaks);
	std::cout << "[subject 예제]" << std::endl;
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	delete cat;
	delete dog;

	{
		int	total_animal = 4;
		Animal *animal[total_animal];

		std::cout << "\n[dog 객체 생성]" << std::endl;
		for (int i = 0; i < (total_animal / 2); i++)
			animal[i] = new Dog();
		std::cout << "\n[cat 객체 생성]" << std::endl;
		for (int i = (total_animal / 2); i < total_animal; i++)
			animal[i] = new Cat();
		std::cout << "\n[animal array delete]" << std::endl;

		
		for (int i = 0; i < total_animal; i++)
			delete animal[i];
	}

	{
		std::cout <<"\n[고양이들 생성]" << std::endl;
		Cat cat1;
		Cat cat2(cat1);
		Cat cat3 = cat1;

		std::cout << "\n[고양이들의 생각]" << std::endl;
		std::cout << cat1.getBrain() << std::endl;
		std::cout << cat2.getBrain() << std::endl;
		std::cout << cat3.getBrain() << std::endl;
		
		std::cout << "\n[고양이 한 마리 생각 바뀜]" << std::endl;
		cat1.setBrain("집에 가고싶다..");
		std::cout << cat1.getBrain() << std::endl;
		std::cout << cat2.getBrain() << std::endl;
		std::cout << cat3.getBrain() << std::endl;

		std::cout << "\n[고양이 두 마리 생각 바뀜]" << std::endl;
		cat2.setBrain("여행 가고싶다..");
		std::cout << cat1.getBrain() << std::endl;
		std::cout << cat2.getBrain() << std::endl;
		std::cout << cat3.getBrain() << std::endl;

		std::cout << "\n[소멸자]" << std::endl;
	}

	{
		std::cout <<"\n[강아지들 생성]" << std::endl;
		Dog dog1;
		Dog	dog2(dog1);
		Dog dog3 = dog1;
		dog2 = dog3;

		std::cout << "\n[강아지들의 생각]" << std::endl;
		std::cout << dog1.getBrain() << std::endl;
		std::cout << dog2.getBrain() << std::endl;
		std::cout << dog3.getBrain() << std::endl;
		
		std::cout << "\n[강아지 한 마리 생각 바뀜]" << std::endl;
		dog1.setBrain("소곡이");
		std::cout << dog1.getBrain() << std::endl;
		std::cout << dog2.getBrain() << std::endl;
		std::cout << dog3.getBrain() << std::endl;

		std::cout << "\n[강아지 두 마리 생각 바뀜]" << std::endl;
		dog2.setBrain("돼지곡이");
		std::cout << dog1.getBrain() << std::endl;
		std::cout << dog2.getBrain() << std::endl;
		std::cout << dog3.getBrain() << std::endl;

		std::cout << "\n[소멸자]" << std::endl;
	}

	return (0);
}
