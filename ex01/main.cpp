#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
        return (1);
    PhoneBook   phonebook;
    int i = -1;
    
    phonebook.readUserCommand(i);
    return (0);
}