#include "Contact.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 * 
 */
Contact::Contact(void)
{
}

/**
 * @brief Destroy the Contact:: Contact object
 * 
 */
Contact::~Contact(void)
{
}

/**
 * @brief Set the first Name object
 * 
 * @param str 
 */
void	Contact::set_firstName(std::string str)
{
	this->firstName = str;
}

/**
 * @brief Set the last Name object
 * 
 * @param str 
 */
void	Contact::set_lastName(std::string str)
{
	this->lastName = str;
}

/**
 * @brief Set the nick Name object
 * 
 * @param str 
 */
void	Contact::set_nickName(std::string str)
{
	this->nickName = str;
}

/**
 * @brief Set the phone Number object
 * 
 * @param str 
 */
void	Contact::set_phoneNumber(std::string str)
{
	this->phoneNumber = str;
}

/**
 * @brief Set the darkest Secret object
 * 
 * @param str 
 */
void	Contact::set_darkestSecret(std::string str)
{
	this->darkestSecret = str;
}

/**
 * @brief Get the first Name object
 * 
 * @return std::string 
 */
std::string	Contact::get_firstName(void) const
{
	return (this->firstName);
}

/**
 * @brief Get the last Name object
 * 
 * @return std::string 
 */
std::string	Contact::get_lastName(void) const
{
	return (this->lastName);
}

/**
 * @brief Get the nick Name object
 * 
 * @return std::string 
 */
std::string	Contact::get_nickName(void) const
{
	return (this->nickName);
}

/**
 * @brief Get the phone Number object
 * 
 * @return std::string 
 */
std::string	Contact::get_phoneNumber(void) const
{
	return (this->phoneNumber);
}

/**
 * @brief Get the darkest Secret object
 * 
 * @return std::string 
 */
std::string	Contact::get_darkestSecret(void) const
{
	return (this->darkestSecret);
}
