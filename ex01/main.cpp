/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:55:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 23:29:11 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "TUI.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "tools.hpp"

void	printTitle() {
	// Font Name: ANSI Shadow
	std::cout << "\033[1;33m";
	std::cout << "██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗" << std::endl;
	std::cout << "██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝" << std::endl;
	std::cout << "██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ " << std::endl;
	std::cout << "██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ " << std::endl;
	std::cout << "██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗" << std::endl;
	std::cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝" << std::endl;
	std::cout << "\033[0m" << std::endl;
}

Contact getContact() {
	Contact contact;
	TUI tui = TUI::getInstance();
	while (true) {
		std::cout << "Please enter the information of the new contact:" << std::endl;
		contact.setFirstName(tui.getString("  Fist name: ", 2));
		contact.setLastName(tui.getString("  Last name: ", 2));
		contact.setNickname(tui.getString("  Nickname: ", 1));
		contact.setPhoneNumber(tui.getSpanishPhone("  Phone number: "));
		contact.setDarkestSecret(tui.getString("  Darkest secret: ", 5));
		std::cout << std::endl << "Contact information:" << std::endl;
		contact.print();
		if (tui.getString("Is this information correct? (*/n) ") != "n")
			break;
	}
	return (contact);
}

int	main(void) {
	PhoneBook	phoneBook;
	TUI			tui = TUI::getInstance();
	bool		running = true;

	#ifdef DEBUG
	phoneBook.addContact(Contact("John", "Doe", "jdoe", "123456789", "I'm John Doe"));
	phoneBook.addContact(Contact("Jane", "Doe", "jadoe", "987654321", "I'm Jane Doe"));
	phoneBook.addContact(Contact("John", "Smith", "jsmith", "123456789", "I'm John Smith"));
	phoneBook.addContact(Contact("Jane", "Smith", "jasmith", "987654321", "I'm Jane Smith"));
	phoneBook.addContact(Contact("John", "Jones", "jjones", "123456789", "I'm John Jones"));
	phoneBook.addContact(Contact("Jane", "Jones", "jajones", "987654321", "I'm Jane Jones"));
	phoneBook.addContact(Contact("John", "Williams", "jwilliams", "123456789", "I'm John Williams"));
	phoneBook.addContact(Contact("Jane", "Williams", "jawilliams", "987654321", "I'm Jane Williams"));
	phoneBook.addContact(Contact("1234567890", "1234567890", "1234567890", "987654321", "I'm Jane Williams"));
	#endif

	printTitle();
	while (running) {
		switch (stocmd(tui.getString("> "))) {
			case EMPTY:
				break;
			case ADD:
				phoneBook.addContact(getContact());
				std::cout << "Contact added successfully" << std::endl;
				break;
			case SEARCH:
				if (phoneBook.getContactCount() == 0) {
					std::cerr << "No contacts" << std::endl;
					break;
				}
				phoneBook.print();
				phoneBook.searchAndPrint((unsigned int) tui.getInt(
					"Index: ", 0, phoneBook.getContactCount() - 1
				));
				break;
			case EXIT:
				running = false;
				break;
			case UNKNOWN:
				std::cerr << "Unknown command" << std::endl;
				std::cerr << "  Valid commands: ADD, SEARCH, EXIT" << std::endl;
				break;
		}
	}
	return (0);
}
