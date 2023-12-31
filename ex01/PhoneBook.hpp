/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:42:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 22:24:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
# include <iomanip> // std::setw, std::setfill
#include "Contact.hpp"

class PhoneBook {
public:
	static const unsigned int	MAX_CONTACTS = 8;

	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& obj);
	PhoneBook& operator=(const PhoneBook& obj);

	void addContact(const Contact contact);
	void searchAndPrint(unsigned int index);
	void print();
	unsigned int getContactCount() const;

private:
	unsigned int				contactCount;
	Contact						contacts[MAX_CONTACTS];
};

#endif
