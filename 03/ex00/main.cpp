#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("CL4P-TP");

	clap.attack("Handsome Jack");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.attack("a Bullymong");
	clap.takeDamage(10);
	clap.attack("Skag");
	clap.beRepaired(10);

	return 0;
}
