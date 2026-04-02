#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called." << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called." << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
	} else {
		_hitPoints -= amount;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! HP is now " << _hitPoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to repair itself!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount << " hit points! HP is now " << _hitPoints << "." << std::endl;
}
