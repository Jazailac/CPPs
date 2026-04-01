#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _value(n << _bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _value(roundf(n * (1 << _bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << _bits);
}

int Fixed::toInt(void) const {
	return this->_value >> _bits;
}

std::ostream& operator<<(std::ostream& o, Fixed const& i) {
	o << i.toFloat();
	return o;
}
