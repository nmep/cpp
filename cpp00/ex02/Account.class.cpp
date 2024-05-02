# include "Account.hpp"

Account::Account(int initial_deposit)
{
	;
}

Account::~Account(void)
{
	;
}

int Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int Account::getNbDeposits( void )
{
	return _nbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _nbWithdrawals;
}