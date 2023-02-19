#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;

	{
		const WrongAnimal*	wrongMeta = new WrongAnimal();
		const WrongAnimal*	wrongCat = new WrongCat();

		std::cout << wrongCat->getType() << " " << std::endl;
		std::cout << wrongMeta->getType() << " " << std::endl;

		wrongCat->makeSound();
		wrongMeta->makeSound();

		delete wrongCat;
		delete wrongMeta;
	}

	return (0);
}