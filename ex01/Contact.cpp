#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret
) {
	#ifdef DEBUG
	std::clog << "Contact constructor called" << std::endl;
	#endif
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
	#ifdef DEBUG
	std::clog << "Contact constructor finished" << std::endl;
	#endif
}

Contact::~Contact() {}

Contact::Contact(const Contact & obj) { *this = obj; }

Contact& Contact::operator=(const Contact& obj) {
	if (this == &obj)
		return (*this);
	this->_firstName = obj._firstName;
	this->_lastName = obj._lastName;
	this->_nickname = obj._nickname;
	this->_phoneNumber = obj._phoneNumber;
	this->_darkestSecret = obj._darkestSecret;
	return (*this);
}

void Contact::print() const {
	std::cout << "=============================================" << std::endl;
	std::cout << "| Contact Info:" << std::endl;
	std::cout << "| First Name: " << this->_firstName << std::endl;
	std::cout << "| Last Name: " << this->_lastName << std::endl;
	std::cout << "| Nickname: " << this->_nickname << std::endl;
	std::cout << "| Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "| Darkest Secret: " << this->_darkestSecret << std::endl;
	std::cout << "=============================================" << std::endl;
}

// Getters
std::string Contact::getFirstName() const { return (this->_firstName); }
std::string Contact::getLastName() const { return (this->_lastName); }
std::string Contact::getNickname() const { return (this->_nickname); }
std::string Contact::getPhoneNumber() const { return (this->_phoneNumber); }
std::string Contact::getDarkestSecret() const { return (this->_darkestSecret); }

// Setters
void Contact::setFirstName(const std::string firstName) { this->_firstName = firstName; }
void Contact::setLastName(const std::string lastName) { this->_lastName = lastName; }
void Contact::setNickname(const std::string nickname) { this->_nickname = nickname; }
void Contact::setPhoneNumber(const std::string phoneNumber) { this->_phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string darkestSecret) { this->_darkestSecret = darkestSecret; }
