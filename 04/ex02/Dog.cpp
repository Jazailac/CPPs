#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(NULL) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other) {
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain); // Deep copy
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}
