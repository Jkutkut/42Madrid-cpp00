/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:45:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 10:44:49 by jre-gonz         ###   ########.fr       */
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
	this->contacts[this->contactCount % MAX_CONTACTS] = contact;
}

void PhoneBook::searchAndPrint(unsigned int index) {
	if (index >= MAX_CONTACTS) {
		std::cerr << "Invalid index. It must be a natural number between 0 and " << MAX_CONTACTS << std::endl;
		return;
	}
	this->contacts[index].print();
}
