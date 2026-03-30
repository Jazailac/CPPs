#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_count;
	int		_oldest;

public:
	PhoneBook();

	void	addContact(const Contact &contact);
	void	displayList() const;
	void	displayContact(int index) const;
	int		getCount() const;
};

#endif
