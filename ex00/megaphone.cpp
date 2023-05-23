#include <iostream>
#include <string>
#include <algorithm>

bool isAlphaNumeric(const std::string &str)
{
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
            return !isalnum(c);
        });
 
    return it == str.end();
}

void shout(std::string str)
{
    for(int x = 0; x < str.length(); x++)
        std::cout << char(toupper(str[x]));
        std::cout << '\n';
}

int main(int ac, char **av)
{
    int ret;
    int i;
    std::string str;

    i = 1;
    ret = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (++ret);
    }
    else
    {
        while (av[i])
        {
            if (isAlphaNumeric(av[i]) && i != 1)
                str.append(", ");
            else
                str.append(" ");
            str.append(av[i]);
            i++;
        }
        shout(str);
    }
    return (ret);
}