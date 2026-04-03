#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(NULL) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain); // Deep copy
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
