#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account() 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created"<< std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "closed"<< std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	++_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << initial_deposit << ';'
		<< "craeted" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";"
			<< "nb_deposits:" << ++this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawel)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:";
	if (this->_amount - withdrawel < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawel << ";";
	this->_amount -= withdrawel;
	std::cout << "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawel;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm* t;

	timer = time(0);
	t = localtime(&timer);
	int year = t->tm_year + 1900;
	int month = t->tm_mon + 1;
	int date = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	int sec = t->tm_sec;

	std::cout << "[" << year;
	if (month < 10)
		std::cout << "0";
	std::cout << month;
	if (date < 10)
		std::cout << "0";
	std::cout << date << "_" << hour << min << sec << "] " ;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}


