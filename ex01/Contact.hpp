#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>

class Contact {
	public:
		Contact(const std::string name, const std::string login, const std::string number);
		~Contact();
		Contact(const Contact & obj);
		Contact& operator=(const Contact& obj);
		void debugPrint();

	private:
		std::string _name;
		std::string _login;
		std::string _number;
};

#endif
