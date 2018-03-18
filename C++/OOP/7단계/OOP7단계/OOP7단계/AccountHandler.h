/*
�����̸� : Account.h
�ۼ��� : ����
������Ʈ ���� : [2017, 07, 17] ���Ϲ��� 0.8
*/

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "HighCreditAccount.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;
	int account_num;

public:
	AccountHandler(void);

	void ShowMenu(void);

	void MakeAccount(void);

	void DepositMoney(void);

	void WithdrawMoney(void);

	void PrintAllInfo(void);

	~AccountHandler(void);
};

#endif
