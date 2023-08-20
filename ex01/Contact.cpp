#include "Contact.hpp"

Contact::Contact(std::string name, std::string login, std::string number) {
	this->_name = name;
	this->_login = login;
	this->_number = number;
}

Contact::~Contact() {}

Contact::Contact(const Contact & obj) { *this = obj; }

Contact& Contact::operator=(const Contact& obj) {
	(void)obj;
	return *this;
}

void Contact::debugPrint() {
	std::cout << "=============================================" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Login: " << this->_login << std::endl;
	std::cout << "Number: " << this->_number << std::endl;
	std::cout << "=============================================" << std::endl;
}
