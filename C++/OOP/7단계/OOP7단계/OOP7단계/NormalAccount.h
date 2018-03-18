#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "BankingCommonDecl.h"
#include "Account.h"

class NormalAccount : public Account
{
private:
	int naratio;
public:
	NormalAccount(int num, int money, string name, int ratio) : Account(num, money, name), naratio(ratio)
	{}

	int get_ratio() const
	{
		return naratio;
	}

	virtual void plus_accMoney(int n)
	{
		Account::plus_accMoney(n + (int)(Account::get_accMoney()*naratio / 100.0));
	}

	virtual void ShowAccInfo(void) const
	{
		Account::ShowAccInfo();
		cout << "ÀÌÀÚÀ² : " << naratio << endl;
	}
};

#endif