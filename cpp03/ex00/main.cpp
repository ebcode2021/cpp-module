#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	default_clap;
	ClapTrap	eunson_clap("eunson");
	ClapTrap	hp_clap("hp_clap");
	ClapTrap	energy_clap("energy_clap");

	// 초기상태
	std::cout << "------------- 초기상태 -------------" << std::endl;
	default_clap.printStatus();
	eunson_clap.printStatus();
	hp_clap.printStatus();
	energy_clap.printStatus();

	// 수리중
	std::cout <<  "------------- 수리중 -------------" << std::endl;
	default_clap.beRepaired(5);
	eunson_clap.beRepaired(7);
	hp_clap.beRepaired(9);
	energy_clap.beRepaired(10);

	// 수리완료
	std::cout <<  "------------- 수리 완료 -------------" << std::endl;
	default_clap.printStatus();
	eunson_clap.printStatus();
	hp_clap.printStatus();
	energy_clap.printStatus();

	// hp_clap Kill
	std::cout <<  "------------- hp_clap 죽이기 -------------" << std::endl;
	hp_clap.takeDamage(19);
	hp_clap.beRepaired(1);
	hp_clap.printStatus();

	// energy_clap Kill
	std::cout <<  "------------- hp_clap 죽이기 -------------" << std::endl;
	for (int i = 0; i < 10; i++)
		energy_clap.beRepaired(1);
	energy_clap.printStatus();

	// attack
	default_clap.attack("minirt");
	eunson_clap.attack("minirt");
	hp_clap.attack("minirt");
	energy_clap.attack("minirt");

	return (0);
}