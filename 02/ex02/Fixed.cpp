#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(int const n) : _value(n << _bits) {
}

Fixed::Fixed(float const n) : _value(roundf(n * (1 << _bits))) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
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

bool Fixed::operator>(const Fixed& other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed res;
	res.setRawBits(this->_value + other._value);
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed res;
	res.setRawBits(this->_value - other._value);
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed res;
	res.setRawBits((long)this->_value * other._value >> _bits);
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed res;
	res.setRawBits(((long)this->_value << _bits) / other._value);
	return res;
}

Fixed& Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& o, Fixed const& i) {
	o << i.toFloat();
	return o;
}
