/*
파일이름 : Account.h
작성자 : 심정
업데이트 정보 : [2017, 07, 17] 파일버전 0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int num, int money, string name) : accNum(num), accMoney(money), accName(name)
{
}

Account::Account(void) : accNum(0), accMoney(0), accName("")
{
}


void Account::set_accNum(int n)
{
	accNum = n;
}

int Account::get_accNum(void) const
{
	return accNum;
}

void Account::set_accMoney(int n)
{
	accMoney = n;
}

void Account::plus_accMoney(int n)
{
	accMoney += n;
}

void Account::minus_accMoney(int n)
{
	accMoney -= n;
}

int Account::get_accMoney(void) const
{
	return accMoney;
}

void Account::set_accName(string n)
{
	accName = n;
}

string Account::get_accName(void) const
{
	return accName;
}

void Account::ShowAccInfo(void) const
{
	cout << "계좌ID : " << accNum << endl;
	cout << "이름 : " << accName << endl;
	cout << "잔액 : " << accMoney << endl;
}