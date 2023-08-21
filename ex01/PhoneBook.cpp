/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:45:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 17:29:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook constructor called" << std::endl;
	this->contactCount = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook& obj) {
	std::cout << "PhoneBook copy constructor called" << std::endl;
	this->contactCount = obj.contactCount;
	for (unsigned int i = 0; i < MAX_CONTACTS; i++)
		this->contacts[i] = obj.contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& obj) {
	if (this == &obj)
		return (*this);
	this->contactCount = obj.contactCount;
	for (unsigned int i = 0; i < MAX_CONTACTS; i++)
		this->contacts[i] = obj.contacts[i];
	return (*this);
}

void PhoneBook::addContact(const Contact contact) {
	if (this->contactCount >= MAX_CONTACTS)
		std::cout << "PhoneBook is full. Replacing oldest." << std::endl;
	std::clog << "Adding " << contact.getName() << " to PhoneBook...";
	this->contacts[this->contactCount % MAX_CONTACTS] = contact;
	std::clog << " [OK]" << std::endl;
	this->contactCount++;
}

void PhoneBook::searchAndPrint(unsigned int index) {
	if (index >= MAX_CONTACTS) {
		std::cerr << "Invalid index. It must be a natural number between 0 and " << MAX_CONTACTS << std::endl;
		return;
	}
	this->contacts[index].print();
}

void PhoneBook::print() {
	std::cout << "---------------------------------------------" << std::endl;
	for (unsigned int i = 0; i < this->contactCount; i++) {
		std::cout << "| " << i << " | ";
		// TODO format name, login and number
		std::cout << this->contacts[i].getName() << " | ";
		std::cout << this->contacts[i].getLogin() << " | ";
		std::cout << this->contacts[i].getNumber() << " |" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}
