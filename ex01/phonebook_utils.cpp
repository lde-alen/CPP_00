#include "phonebook.hpp"

std::string truncate(std::string str, size_t len, const char *ellipsis)
{
    std::string tmp;

    tmp = str;
    if (str.length() > len)
    {
        tmp.resize(len);
        tmp.replace(len - 1, 1, ellipsis);
    }
    return (tmp);
}