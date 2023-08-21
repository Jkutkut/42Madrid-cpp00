/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:45:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 22:42:08 by jre-gonz         ###   ########.fr       */
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
	std::clog << "Adding " << contact.getFirstName() << " " << contact.getLastName() << " to PhoneBook...";
	this->contacts[this->contactCount % MAX_CONTACTS] = contact;
	std::clog << " [OK]" << std::endl;
	this->contactCount++;
}

void PhoneBook::searchAndPrint(unsigned int index) {
	if (index >= MAX_CONTACTS) {
		std::cerr << "Invalid index. It must be a natural number between 0 and ";
		std::cerr << this->getContactCount() << std::endl;
		return;
	}
	this->contacts[index].print();
}

void printField(std::string field) {
	if (field.length() < 10) {
		std::cout << std::setw(10) << std::setfill(' ');
		std::cout << field;
	}
	else {
		std::cout << field.substr(0, 9) << ".";
	}
}

void printHeader() {
	std::cout << "|";
	printField("index");
	std::cout << "|";
	printField("first name");
	std::cout << "|";
	printField("last name");
	std::cout << "|";
	printField("nickname");
	std::cout << "|";
	printField("phone number");
	std::cout << "|";
	printField("darkest secret");
	std::cout << "|" << std::endl;
}

void printRow(unsigned int row, Contact contact) {
	std::cout << "|         " << row << "|";
	printField(contact.getFirstName());
	std::cout << "|";
	printField(contact.getLastName());
	std::cout << "|";
	printField(contact.getNickname());
	std::cout << "|";
	printField(contact.getPhoneNumber());
	std::cout << "|";
	printField(contact.getDarkestSecret());
	std::cout << "|" << std::endl;
}

void PhoneBook::print() {
	printHeader();
	std::cout << std::setw(6 * (10 + 1) + 1) << std::setfill('-') << "" << std::endl;
	for (unsigned int i = 0; i < this->getContactCount(); i++) {
		printRow(i, this->contacts[i]);
	}
	std::cout << std::setw(6 * (10 + 1) + 1) << std::setfill('-') << "" << std::endl;
}

unsigned int PhoneBook::getContactCount() const {
	// min(this->contactCount, MAX_CONTACTS);
	if (this->contactCount < MAX_CONTACTS)
		return (this->contactCount);
	return (MAX_CONTACTS);
}
