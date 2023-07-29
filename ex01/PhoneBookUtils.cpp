#include "PhoneBook.hpp"
/**
 * @brief Trim the trailing spaces of a string.
 * 
 * @param str 
 * @return std::string 
 */
std::string trimTrailing(std::string str)
{
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}

/**
 * @brief Truncate a string to a given length and replace the last character with an ellipsis.
 * 
 * @param str 
 * @param len 
 * @param ellipsis 
 * @return std::string 
 */
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

/**
 * @brief Check if a string contains only spaces.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	containsOnlySpace(std::string const &str)
{
	return str.find_first_not_of(" ") ==
		std::string::npos;
}

/**
 * @brief Check if a string contains only numbers
 * 
 * @param str 
 * @return true if there are only numbers
 * @return false if there is something other than number
 */
bool	containsOnlyNumbers(std::string const &str)
{
	return str.find_first_not_of("0123456789") ==
		std::string::npos;
}

/**
 * @brief Trim the spaces in the middle of  a string.
 * @note This function is really not efficient but it is the only way I found to do it
 * 		in a c++ approach while following c++98 restrictions.
 * @param str 
 * @return std::string 
 */
std::string trim(std::string str)
{
	std::string trimmed = trimTrailing(str);
	std::string temp;
	std::string delimiter = " ";
	std::string token;
	size_t		pos = 0;

	while ((pos = trimmed.find_first_of(delimiter)) != std::string::npos)
	{
		token = trimmed.substr(0, pos);
		if (token != "")
			temp += token + " ";
		trimmed.erase(0, pos + delimiter.length());
		pos = trimmed.find_first_of(delimiter);
		if (pos == std::string::npos)
			temp += trimmed;
		else
			temp += trimmed.substr(0, pos) + " ";
	}
	if (temp.empty())
		return (trimmed);
	return (temp);
}
