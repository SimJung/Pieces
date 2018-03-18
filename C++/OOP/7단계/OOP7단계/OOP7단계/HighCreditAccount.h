#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;

public:
	HighCreditAccount(int num, int money, string name, int ratio, int sratio) : NormalAccount(num, money, name, ratio), specialRatio(sratio)
	{}

	virtual void plus_accMoney(int n)
	{
		switch (specialRatio)
		{
		case 0:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 7) / 100.0));
			break;
		case 1:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 4) / 100.0));
			break;
		case 2:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 2) / 100.0));
			break;
		}

	}

	virtual void ShowAccInfo(void) const
	{
		NormalAccount::ShowAccInfo();
		cout << "신용등급(1toA, 2toB, 3toC) : " << specialRatio << endl;
	}
};

#endif
