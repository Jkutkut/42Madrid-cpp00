/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:55:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/20 21:50:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "TUI.hpp"
#include "Contact.hpp"

int	main(void) {
	Contact test = Contact(
		"Jorge",
		"jre-gonz",
		"123123123"
	);
	test.debugPrint();

	TUI tui = TUI::getInstance();
	std::cout << "Hello, world!" << std::endl;
	std::string name = tui.getString("Enter your name: ");
	std::cout << "Your name is " << name << std::endl;
	name = tui.getString("String len [5, 10]: ", 5, 10);
	std::cout << "A string witd def: " << name << std::endl;
	return (0);
}
