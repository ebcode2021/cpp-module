#include <iostream>

#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	struct Data data;

	data.num = 42;

	std::cout << "[serialize]" << std::endl;
	uintptr_t	save_data = serialize(&data);
	std::cout << save_data << std::endl;

	std::cout << "[deserialize]" << std::endl;
	Data*	restore_data = deserialize(save_data);

	std::cout << restore_data << std::endl;
	std::cout << data.num << std::endl;
	return (0);
}
