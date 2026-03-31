#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << "Creating Zombie: " << name << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << ": is dead" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
