/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:07:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 23:09:55 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.hpp"

std::string toUpper(std::string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

t_commands	stocmd(std::string command) {
	if (command.length() == 0)
		return (EMPTY);
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
