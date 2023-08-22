/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:19:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/08/22 18:13:11 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = 0;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_nbAccounts++;
	// TODO
}

Account::~Account() {
	Account::_nbAccounts--;
	// TODO
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_nbAccounts++;
	// TODO
}

// GETTERS

int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int	Account::getTotalAmount( void ) { return Account::_totalAmount; }
int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

// FUNCTIONS

void	Account::_displayTimestamp( void ) {
	time_t	c_time = 0;
	struct tm * time_info;
	char timeString[18];

	time(&c_time);
	time_info = localtime(&c_time);
	strftime(timeString, sizeof(timeString), "[%Y%m%d_%H%M%S]", time_info);
	std::cout << timeString;
}

void	Account::makeDeposit( int deposit ) {
	// TODO
	(void)deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	(void)withdrawal;
	return true;// TODO
}

int		Account::checkAmount( void ) const {
	// TODO
	return 0;
}

void	Account::displayStatus( void ) const {
	// TODO
}


