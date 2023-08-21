/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:42:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 09:24:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& obj);
	PhoneBook& operator=(const PhoneBook& obj);

	void addContact(const Contact contact);
	void searchAndPrint(unsigned int index);

private:
	static const unsigned int	MAX_CONTACTS = 8;
	unsigned int				contactCount;
	Contact						contacts[MAX_CONTACTS];
};

#endif
