#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

void	PhoneBook::addContact(const Contact &contact)
{
	_contacts[_oldest] = contact;
	_oldest = (_oldest + 1) % 8;
	if (_count < 8)
		_count++;
}

static std::string	truncate(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::displayList() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cout << "First name:     " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name:      " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number:   " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

int	PhoneBook::getCount() const { return _count; }
