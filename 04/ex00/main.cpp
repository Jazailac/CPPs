#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "--- Test ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j    = new Dog();
	const Animal* i    = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "--- WrongAnimal Test ---" << std::endl;
	const WrongAnimal* wrong     = new WrongAnimal();
	const WrongAnimal* wrongCat  = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrong->makeSound();

	std::cout << std::endl << "--- Cleanup ---" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;

	return 0;
}
