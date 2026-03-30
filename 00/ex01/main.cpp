#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string	getField(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty())
			return input;
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}

static void	addContact(PhoneBook &phonebook)
{
	Contact contact;

	contact.setFirstName(getField("First name: "));
	if (std::cin.eof()) return;
	contact.setLastName(getField("Last name: "));
	if (std::cin.eof()) return;
	contact.setNickname(getField("Nickname: "));
	if (std::cin.eof()) return;
	contact.setPhoneNumber(getField("Phone number: "));
	if (std::cin.eof()) return;
	contact.setDarkestSecret(getField("Darkest secret: "));
	if (std::cin.eof()) return;
	phonebook.addContact(contact);
	std::cout << "Contact added successfully." << std::endl;
}

static void	searchContact(PhoneBook &phonebook)
{
	if (phonebook.getCount() == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}
	phonebook.displayList();
	std::cout << "Enter index: ";
	std::string line;
	if (!std::getline(std::cin, line))
		return;
	int index;
	bool valid = !line.empty();
	index = 0;
	for (size_t i = 0; i < line.size() && valid; i++)
	{
		if (line[i] < '0' || line[i] > '9')
			valid = false;
		else
			index = index * 10 + (line[i] - '0');
	}
	if (!valid)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	phonebook.displayContact(index);
}

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			addContact(phonebook);
		else if (command == "SEARCH")
			searchContact(phonebook);
		else if (command == "EXIT")
			break;
	}
	return 0;
}
