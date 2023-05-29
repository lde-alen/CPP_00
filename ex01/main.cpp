#include "phonebook.hpp"

int main(void)
{
    Phonebook   phonebook;

    for (int i = 0; i < 8; i++)
    {
        phonebook.print(phonebook, i);
    }
    return (0);
}