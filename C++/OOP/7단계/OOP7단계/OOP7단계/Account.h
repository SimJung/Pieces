/*
�����̸� : Account.h
�ۼ��� : ����
������Ʈ ���� : [2017, 07, 17] ���Ϲ��� 0.8
*/


#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>
#include "BankingCommonDecl.h"

class Account
{
private:
	int accNum;
	int accMoney;
	string accName;

public:
	Account(int num, int money, string name);

	Account(void);

	void set_accNum(int n);

	int get_accNum(void) const;

	void set_accMoney(int n);

	virtual void plus_accMoney(int n);

	void minus_accMoney(int n);

	int get_accMoney(void) const;

	void set_accName(string n);

	string get_accName(void) const;

	virtual void ShowAccInfo(void) const;
};

#endif
