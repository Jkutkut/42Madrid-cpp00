#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>

class Contact {
	public:
		Contact();
		Contact(
			std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string darkestSecret
		);
		~Contact();
		Contact(const Contact & obj);
		Contact& operator=(const Contact& obj);
		void print() const;

		// Getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		// Setters
		void setFirstName(const std::string firstName);
		void setLastName(const std::string lastName);
		void setNickname(const std::string nickname);
		void setPhoneNumber(const std::string phoneNumber);
		void setDarkestSecret(const std::string darkestSecret);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
