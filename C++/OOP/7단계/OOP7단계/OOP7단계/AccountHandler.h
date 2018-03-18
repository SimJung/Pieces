/*
파일이름 : Account.h
작성자 : 심정
업데이트 정보 : [2017, 07, 17] 파일버전 0.8
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
