/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:55:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 17:26:32 by jre-gonz         ###   ########.fr       */
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
		contact.setName(tui.getString("  Name: "));
		contact.setLogin(tui.getString("  Login: "));
		contact.setNumber(tui.getString("  Number: ")); // TODO validate
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
	phoneBook.addContact(Contact("John", "john", "123456789"));
	phoneBook.addContact(Contact("Jane", "jane", "987654321"));
	phoneBook.addContact(Contact("Jack", "jack", "123123123"));
	phoneBook.addContact(Contact("Jill", "jill", "321321321"));
	phoneBook.addContact(Contact("James", "james", "456456456"));
	phoneBook.addContact(Contact("Jenny", "jenny", "654654654"));
	phoneBook.addContact(Contact("Jared", "jared", "789789789"));
	phoneBook.addContact(Contact("Jasmine", "jasmine", "987987987")); // TODO remove

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
					"Index: ",
					0,
					PhoneBook::MAX_CONTACTS - 1 // TODO use min(amount, max)
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
