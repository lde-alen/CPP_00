#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"
# include <sstream>

class PhoneBook
{
	private:
		std::string command;
		Contact     contacts[8];
		int         index[8];

		bool        containsOnlyValid(std::string const &str);
		void        search(void);
		void        print(PhoneBook phonebook, int index, int flag);
		void        init(void);
		int         getindex(int index);
		int         checkInput(int *i);
		Contact     get_contact(int index);
		void        funcPtrInit(bool (PhoneBook::*funcPtr[5])(int));
		int 		add(int i);
		bool        add_firstName(int i);
		bool	    add_lastName(int i);
		bool	    add_nickName(int i);
		bool	    add_darkestSecret(int i);
		bool	    add_phoneNumber(int i);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void        readUserCommand(int i);
};
	std::string		truncate(std::string str, size_t len, const char *ellipsis);
	bool            containsOnlySpace(std::string const &str);
	bool            containsOnlyNumbers(std::string const &str);
	std::string     trim(std::string str);
#endif
