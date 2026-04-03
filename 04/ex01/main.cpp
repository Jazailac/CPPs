#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "---  Test (delete through base pointer) ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl << "--- Array Test (half Dog, half Cat) ---" << std::endl;
	const int SIZE = 10;
	Animal* animals[SIZE];
	for (int idx = 0; idx < SIZE / 2; idx++)
		animals[idx] = new Dog();
	for (int idx = SIZE / 2; idx < SIZE; idx++)
		animals[idx] = new Cat();
	for (int idx = 0; idx < SIZE; idx++)
		delete animals[idx];

	std::cout << std::endl << "--- Deep Copy Test ---" << std::endl;
	Dog original;
	original.getBrain()->ideas[0] = "Chase the cat";
	original.getBrain()->ideas[1] = "Eat the food";

	Dog copy(original);
	std::cout << "Original idea[0]: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy    idea[0]: " << copy.getBrain()->ideas[0] << std::endl;

	copy.getBrain()->ideas[0] = "Sleep all day";
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original idea[0]: " << original.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy    idea[0]: " << copy.getBrain()->ideas[0] << std::endl;

	return 0;
}
