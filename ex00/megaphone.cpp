#include <iostream>
#include <string>

void shout(std::string str)
{
	for(size_t x = 0; x < str.length(); x++)
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
			str.append(av[i]);
			i++;
		}
		shout(str);
	}
	return (ret);
}