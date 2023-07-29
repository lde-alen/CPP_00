#include "PhoneBook.hpp"

/**
 * @brief Initializes the phonebook creating an empty array[8] of contacts with the respective
 * indexes from 1 - 8.
 * 
 */
void	PhoneBook::init(void)
{
	for (int i = 0; i < 8; i++)
	{
		PhoneBook::index[i] = i + 1;
		PhoneBook::contacts[i].set_firstName("");
		PhoneBook::contacts[i].set_lastName("");
		PhoneBook::contacts[i].set_nickName("");
		PhoneBook::contacts[i].set_phoneNumber("");
		PhoneBook::contacts[i].set_darkestSecret("");
	}
}

/**
 * @brief Check if a string contains only alphanumerical characters and space.
 * 
 * @param str 
 * @return true 
 * @return false 
 * @todo modify in order to accept as argument "name1 name2" && trim spaces before and after and between 
 * and return true or false using a ternary operator.
 */
bool PhoneBook::containsOnlyValid(std::string const &str)
{
	return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") ==
		std::string::npos;
}

/**
 * @brief Requests the user to enter a string for a first name and then adds it to the contact. The return value is decided if everything went well or not.
 * 
 * @param i 
 * @return true 
 * @return false 
 */
bool	PhoneBook::add_firstName(int i)
{
	std::string firstName;
	
	std::cout << "Please enter a first name: ";
	if (std::getline(std::cin, firstName))
	{
		if ((firstName == "" || containsOnlySpace(firstName) || !containsOnlyValid(firstName)) && !std::cin.eof())
		{
			std::cout << "Invalid first name" << std::endl;
			return (false);
		}
		firstName = trim(firstName);
		contacts[i].set_firstName(firstName);
		return (true);
	}
	return (false);
}

/**
 * @brief Requests the user to enter a string for a last name and then adds it to the contact. The return value is decided if everything went well or not.
 * 
 * @param i
 * @return true
 * @return false
 */
bool	PhoneBook::add_lastName(int i)
{
	std::string lastName;
	
	std::cout << "Please enter a last name: ";
	if (std::getline(std::cin, lastName))
	{
		if ((lastName == "" || containsOnlySpace(lastName) || !containsOnlyValid(lastName)) && !std::cin.eof())
		{
			std::cout << "Invalid last name" << std::endl;
			return (false);
		}
		lastName = trim(lastName);
		contacts[i].set_lastName(lastName);
		return (true);
	}
	return (false);
}

/**
 * @brief Requests the user to enter a string for a nickname and then adds it to the contact. The return value is decided if everything went well or not.
 * 
 * @param i 
 * @return true
 * @return false
 */
bool	PhoneBook::add_nickName(int i)
{
	std::string nickName;
	
	std::cout << "Please enter a nickname: ";
	if(std::getline(std::cin, nickName))
	{
		if ((nickName == ""  || containsOnlySpace(nickName) || !containsOnlyValid(nickName)) && !std::cin.eof())
		{
			std::cout << "Invalid nickname" << std::endl;
			return (false);
		}
		nickName = trim(nickName);
		contacts[i].set_nickName(nickName);
		return (true);
	}
	return (false);
}

/**
 * @brief Requests the user to enter a string for a darkest secret and then adds it to the contact. The return value is decided if everything went well or not.
 * 
 * @param i 
 * @return true 
 * @return false 
 */
bool	PhoneBook::add_darkestSecret(int i)
{
	std::string darkestSecret;
	
	std::cout << "Please enter darkest secret: ";
	if (std::getline(std::cin, darkestSecret))
	{	
		if ((darkestSecret == ""  || containsOnlySpace(darkestSecret) || !containsOnlyValid(darkestSecret)) && !std::cin.eof())
		{
			std::cout << "Invalid darkest secret" << std::endl;
			return (false);
		}
		contacts[i].set_darkestSecret(darkestSecret);
		return (true);
	}
	return (false);
}

/**
 * @brief Requests the user to enter a string for a phone number and returns it.
 * 
 * @return std::string 
 */
bool	PhoneBook::add_phoneNumber(int i)
{
	std::string phoneNumber;

	std::cout << "Please enter phone number: ";
	if(std::getline(std::cin, phoneNumber))
	{
		if ((phoneNumber == "" || !containsOnlyNumbers(phoneNumber)) && !std::cin.eof())
		{
			std::cout << "Invalid phone number" << std::endl;
			return (false);
		}
		contacts[i].set_phoneNumber(phoneNumber);
		return (true);
	}
	return (false);
}

/**
 * @brief Initializes the function pointer array with the respective functions.
 * 
 * @param funcPtr 
 */
void	PhoneBook::funcPtrInit(bool (PhoneBook::*funcPtr[5])(int))
{
	funcPtr[0] = &PhoneBook::add_firstName;
	funcPtr[1] = &PhoneBook::add_lastName;
	funcPtr[2] = &PhoneBook::add_nickName;
	funcPtr[3] = &PhoneBook::add_phoneNumber;
	funcPtr[4] = &PhoneBook::add_darkestSecret;
}

int	PhoneBook::add(int i)
{
	bool		(PhoneBook::*funcPtr[5])(int);
	int			index = 0;

	funcPtrInit(funcPtr);
	while (index < 5 && !std::cin.eof())
		if ((this->*funcPtr[index])(i) == true)
				index++;
	std::cout << "Contact added" << std::endl;
	return (1);
}

/**
 * @brief Search for a contact by index and print it. If the index is invalid, it will ask the user to enter a valid index.
 * 
 */
void	PhoneBook::search(void)
{
	std::string index;
	std::stringstream ss(index);
	int i = 0;

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int j = 0; j < 8; j++)
		PhoneBook::print(*this, j, 0);
	do
	{
		std::cout << "Please enter an index: "; 
		std::getline(std::cin, index);
		ss << index;
		ss >> i;
		if (((i < 1 || i > 8) || !containsOnlyNumbers(index)) && !std::cin.eof())
			std::cout << "Invalid index" << std::endl;
		ss.clear();
		ss.str(std::string());
	} while ((!containsOnlyNumbers(index) || (i > 8 || i < 1)) && !std::cin.eof());
	
	PhoneBook::print(*this, i - 1, 1);
}

/**
 * @brief Check if the user input is valid and then calls the respective function.
 * 
 * @param i 
 * @return int 
 */
int	PhoneBook::checkInput(int * i)
{
	std::getline(std::cin, PhoneBook::command);
	if (PhoneBook::command == "ADD")
	{
		if (*i == 7)
			*i = -1;
		(*i)++;
		if (PhoneBook::add(*i))
			return (0);
	}
	else if (PhoneBook::command == "SEARCH")
		PhoneBook::search();
	else if (PhoneBook::command == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			std::cin.clear();
			return (-1);
		}
	else
		std::cout << "Invalid command, please use ADD, SEARCH or EXIT" << std::endl;
	return (0);
}

/**
 * @brief Reads the user command and checks if it is valid. It also keeps track of the number of contacts added.
 * 
 * @param i 
 */
void	PhoneBook::readUserCommand(int i)
{
	while (!std::cin.eof())
	{
		std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
		if (PhoneBook::checkInput(&i) == -1)	
			break;
	}
}

/**
 * @brief Construct a new PhoneBook:: Phonebook object
 * 
 */
PhoneBook::PhoneBook(void)
{
	PhoneBook::init();
}

/**
 * @brief Destroy the PhoneBook:: Phonebook object
 * 
 */
PhoneBook::~PhoneBook(void)
{
}

/**
 * @brief Get the contact object
 * 
 * @param i 
 * @return Contact 
 */
Contact PhoneBook::get_contact(int i)
{
	return (contacts[i]);
}

/**
 * @brief Get the index object
 * 
 * @param i 
 * @return int 
 */
int	PhoneBook::getindex(int i)
{
	return (index[i]);
}

/**
 * @brief Print the contact information in a table format. If flag is 0, it will print the contact information in a table format. If flag is 1, it will print ALL the contact information in a list format.
 * 
 * @param phonebook 
 * @param i 
 * @param flag 
 */
void PhoneBook::print(PhoneBook phonebook, int i, int flag)
{
	if (flag == 0) 
	{
		std::cout
			<< std::setw(10) << std::right << phonebook.getindex(i)
			<< "|"
			<< std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_firstName(), 10, ".")
			<< "|"
			<< std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_lastName(), 10, ".")
			<< "|"
			<< std::setw(10) << std::right << truncate(phonebook.get_contact(i).get_nickName(), 10, ".")
			<< std::endl;
	} 
	else
	{
		std::cout << "\n" << "First name: " << phonebook.get_contact(i).get_firstName() << std::endl;
		std::cout << "Last name: " << phonebook.get_contact(i).get_lastName() << std::endl;
		std::cout << "Nickname: " << phonebook.get_contact(i).get_nickName() << std::endl;
		std::cout << "Phone number: " << phonebook.get_contact(i).get_phoneNumber() << std::endl;
		std::cout << "Darkest secret: " << phonebook.get_contact(i).get_darkestSecret() << "\n" << std::endl;
	}
}