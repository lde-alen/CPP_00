#include <iostream>
#include <string>

void shout(std::string str)
{
    for(int x = 0; x < str.length(); x++)
        std::cout << char(toupper(str[x]));
}

int main(int ac, char **av)
{
    int ret;

    ret = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (++ret);
    }
    else
        shout(av[1]);
    return (ret);
}