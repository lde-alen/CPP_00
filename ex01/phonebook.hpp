#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

# include "contact.hpp"

class Phonebook
{
    private:
        Contact _contacts[8];
        int     _index[8];

    public:
        Phonebook(void);
        ~Phonebook(void);

        void        add(void);
        void        search(void);
        void        print(Phonebook phonebook, int index);
        void        exit(void);

        Contact get_contact(int index);
        int     get_index(int index);
};


 std::string truncate(std::string str, size_t len, const char *ellipsis);
#endif
