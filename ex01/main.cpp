/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:55:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 18:25:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "TUI.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

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

std::string toUpper(std::string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

typedef enum e_commands {
	ADD,
	SEARCH,
	EXIT,
	UNKNOWN
} t_commands;

t_commands	stocmd(std::string command) {
	command = toUpper(command);
	if (command.compare("ADD") == 0)
		return (ADD);
	else if (command == "SEARCH")
		return (SEARCH);
	else if (command == "EXIT")
		return (EXIT);
	else
		return (UNKNOWN);
}

Contact getContact() {
	Contact contact;
	TUI tui = TUI::getInstance();

	while (true) {
		std::cout << "Please enter the information of the new contact:" << std::endl;
		contact.setFirstName(tui.getString("  Fist name: "));
		contact.setLastName(tui.getString("  Last name: "));
		contact.setNickname(tui.getString("  Nickname: "));
		contact.setPhoneNumber(tui.getString("  Phone number: ")); // TODO validate
		contact.setDarkestSecret(tui.getString("  Darkest secret: "));
		std::cout << "Contact information:" << std::endl;
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

	printTitle();

	phoneBook.addContact(Contact("John", "Doe", "jdoe", "123456789", "I'm John Doe"));
	phoneBook.addContact(Contact("Jane", "Doe", "jadoe", "987654321", "I'm Jane Doe"));
	phoneBook.addContact(Contact("John", "Smith", "jsmith", "123456789", "I'm John Smith"));
	phoneBook.addContact(Contact("Jane", "Smith", "jasmith", "987654321", "I'm Jane Smith"));
	phoneBook.addContact(Contact("John", "Jones", "jjones", "123456789", "I'm John Jones"));
	phoneBook.addContact(Contact("Jane", "Jones", "jajones", "987654321", "I'm Jane Jones"));
	phoneBook.addContact(Contact("John", "Williams", "jwilliams", "123456789", "I'm John Williams"));
	phoneBook.addContact(Contact("Jane", "Williams", "jawilliams", "987654321", "I'm Jane Williams"));

	while (running) {
		switch (stocmd(tui.getString("> "))) {
			case ADD:
				phoneBook.addContact(getContact());
				std::cout << "Contact added" << std::endl;
				break;
			case SEARCH:
				// if no contacts, print error
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
				std::cerr << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
				break;
		}
	}
	return (0);
}
