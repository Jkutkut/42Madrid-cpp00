/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:07:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/21 23:15:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <string>

typedef enum e_commands {
	ADD,
	SEARCH,
	EXIT,
	EMPTY,
	UNKNOWN
} t_commands;

std::string	toUpper(std::string str);
t_commands	stocmd(std::string command);

#endif
