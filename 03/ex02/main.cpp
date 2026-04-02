#include "FragTrap.hpp"

int main() {
	std::cout << "--- Construction ---" << std::endl;
	FragTrap frag("FR4G-TP");
	std::cout << "--- Action ---" << std::endl;
	frag.attack("Handsome Jack");
	frag.takeDamage(50);
	frag.beRepaired(25);
	frag.highFivesGuys();
	std::cout << "--- Destruction ---" << std::endl;

	return 0;
}
