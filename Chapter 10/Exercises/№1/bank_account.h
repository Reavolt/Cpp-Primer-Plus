#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_
#include <string>

//-------------------------------------------------------------------------------------------------
class Bank_account
{
private:
	std::string name_depositor;
	std::string account_number;
	unsigned int balance;
public:
	Bank_account();
	Bank_account(const std::string& name_dep, const std::string& acc_num, double bal);
	~Bank_account();
	void show_account();
	void add_balance(double bal);
	void cash_withdrawal(double bal);
};
//-------------------------------------------------------------------------------------------------
#endif // BANK_ACCOUNT_H_