#include "Contact.hpp"
// TODO Check required information
Contact::Contact() {}

Contact::Contact(std::string name, std::string login, std::string number) {
	this->_name = name;
	this->_login = login;
	this->_number = number;
}

Contact::~Contact() {}

Contact::Contact(const Contact & obj) { *this = obj; }

Contact& Contact::operator=(const Contact& obj) {
	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	this->_login = obj._login;
	this->_number = obj._number;
	return (*this);
}

void Contact::print() const {
	std::cout << "=============================================" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Login: " << this->_login << std::endl;
	std::cout << "Number: " << this->_number << std::endl;
	std::cout << "=============================================" << std::endl;
}

// Getters
std::string Contact::getName() const { return this->_name; }
std::string Contact::getLogin() const { return this->_login; }
std::string Contact::getNumber() const { return this->_number; }

// Setters
void Contact::setName(std::string name) { this->_name = name; }
void Contact::setLogin(std::string login) { this->_login = login; }
void Contact::setNumber(std::string number) { this->_number = number; }
