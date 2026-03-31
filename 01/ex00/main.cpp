#include "Zombie.hpp"

int main() {
	std::cout << "--- Stack Zombie ---" << std::endl;
	randomChump("Chumpy");

	std::cout << "\n--- Heap Zombie ---" << std::endl;
	Zombie* heapZombie = newZombie("Heapy");
	heapZombie->announce();
	delete heapZombie;

	return 0;
}
