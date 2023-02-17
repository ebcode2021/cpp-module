#include <iostream>
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	default_clap;
	ScavTrap	eunson_clap("eunson");
	ScavTrap	hp_clap("hp_clap");
	ScavTrap	energy_clap("energy_clap");

	// 초기상태
	std::cout << "\n------------- 초기상태 -------------" << std::endl;
	default_clap.printStatus();
	eunson_clap.printStatus();
	hp_clap.printStatus();
	energy_clap.printStatus();

	// 수리중
	std::cout <<  "\n------------- 수리중 -------------" << std::endl;
	default_clap.beRepaired(5);
	eunson_clap.beRepaired(7);
	hp_clap.beRepaired(9);
	energy_clap.beRepaired(10);

	// 수리완료
	std::cout <<  "\n------------- 수리 완료 -------------" << std::endl;
	default_clap.printStatus();
	eunson_clap.printStatus();
	hp_clap.printStatus();
	energy_clap.printStatus();

	// hp_clap Kill
	std::cout <<  "\n------------- hp_clap 죽이기 -------------" << std::endl;
	hp_clap.takeDamage(1000);
	hp_clap.beRepaired(1);
	hp_clap.printStatus();

	// attack
	std::cout <<  "\n------------- attack -------------" << std::endl;
	default_clap.attack("minirt");
	eunson_clap.attack("minirt");
	hp_clap.attack("minirt");
	energy_clap.attack("minirt");

	// guardGate
	std::cout <<  "\n------------- guardGate -------------" << std::endl;
	default_clap.guardGate();
	eunson_clap.guardGate();
	hp_clap.guardGate();
	energy_clap.guardGate();

	// destructor
	std::cout <<  "\n------------- destructor -------------" << std::endl;
	return (0);
}