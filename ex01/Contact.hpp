#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact(void);
		~Contact(void);

		void		set_firstName(std::string firstName);
		void		set_lastName(std::string lastName);
		void		set_nickName(std::string nickName);
		void		set_phoneNumber(std::string phoneNumber);
		void		set_darkestSecret(std::string darkestSecret);

		std::string	get_firstName(void) const;
		std::string	get_lastName(void) const;
		std::string	get_nickName(void) const;
		std::string	get_phoneNumber(void) const;
		std::string	get_darkestSecret(void) const;
};

#endif