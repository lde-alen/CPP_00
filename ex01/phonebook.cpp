#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
    for (int i = 0; i < 8; i++)
    {
        Phonebook::_index[i] = i + 1;
        Phonebook::_contacts[i].set_firstName("");
        Phonebook::_contacts[i].set_lastName("");
        Phonebook::_contacts[i].set_nickName("");
        Phonebook::_contacts[i].set_phoneNumber("");
        Phonebook::_contacts[i].set_darkestSecret("");
    }
}

Phonebook::~Phonebook(void)
{
    
}

Contact Phonebook::get_contact(int i)
{
    return (_contacts[i]);
}

int    Phonebook::get_index(int i)
{
    return (_index[i]);
}

void Phonebook::print(Phonebook phonebook, int i)
{
    std::cout
        << std::setw(10) << std::right << phonebook.get_index(i)
        << "|"
        << std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_firstName(), 10, ".")
        << "|"
        << std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_lastName(), 10, ".")
        << "|"
        << std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_nickName(), 10, ".")
        << "|"""
        << std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_phoneNumber(), 10, ".")
        << "|"
        << std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_darkestSecret(), 10, ".")
        << std::endl;
}