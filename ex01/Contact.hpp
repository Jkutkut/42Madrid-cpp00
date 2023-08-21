#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>

class Contact {
	public:
		Contact();
		Contact(const std::string name, const std::string login, const std::string number);
		~Contact();
		Contact(const Contact & obj);
		Contact& operator=(const Contact& obj);
		void print();

		std::string getName() const;
		std::string getLogin() const;
		std::string getNumber() const;

		void setName(const std::string name);
		void setLogin(const std::string login);
		void setNumber(const std::string number);

	private:
		std::string _name;
		std::string _login;
		std::string _number;
};

#endif
