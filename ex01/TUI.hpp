/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:57:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/20 22:04:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUI_HPP_
#define TUI_HPP_

#include <iostream>

class TUI {
public:
	TUI();
	TUI(const TUI & obj); // copy constructor
	TUI& operator=(const TUI& obj); // assignment operator
	~TUI();

	static TUI& getInstance();

	std::string getString(std::string question);
	std::string getString(std::string question, unsigned int minLength, unsigned int maxLength);

	//std::string getSpanishPhone(std::string question);

	int getInt(std::string question);
	int getInt(std::string question, int minValue);
	int getInt(std::string question, int minValue, int maxValue);

protected:
	static TUI* instance;
	// static std::string trim(std::string& str);
		// static bool hasAny(const std::string& set, char c);
};

#endif  // TUI_HPP_
