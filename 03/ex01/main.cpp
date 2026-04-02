#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Construction ---" << std::endl;
	ScavTrap scav("SC4V-TP");
	std::cout << "--- Action ---" << std::endl;
	scav.attack("Handsome Jack");
	scav.takeDamage(50);
	scav.beRepaired(25);
	scav.guardGate();
	std::cout << "--- Destruction ---" << std::endl;

	return 0;
}
