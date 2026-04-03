#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// new Animal() would now FAIL to compile — Animal is abstract
	// const Animal* meta = new Animal(); // <- This line would give a compile error

	std::cout << "--- Abstract Animal Test ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl << "--- Deep Copy Test ---" << std::endl;
	Dog original;
	original.getBrain()->ideas[0] = "Chase the cat";
	Dog copy(original);
	copy.getBrain()->ideas[0] = "Sleep all day";
	std::cout << "Original: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy:     " << copy.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl << "--- Cleanup ---" << std::endl;
	delete j;
	delete i;

	return 0;
}
