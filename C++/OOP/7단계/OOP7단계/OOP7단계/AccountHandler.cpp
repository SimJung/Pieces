#include "AccountHandler.h"

AccountHandler::AccountHandler(void) : account_num(0) {}

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void AccountHandler::MakeAccount(void)
{
	int num, money, norh, ratio, sratio;
	string name;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌	2.신용신뢰계좌" << endl;
	cout << "선택 : ";

	cin >> norh;

	if (norh == 1)
		cout << "[보통예금계좌 개설]" << endl;
	else if (norh == 2)
		cout << "[신용신뢰계좌 개설]" << endl;

	cout << "계좌ID : "; cin >> num;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << "이자율 : "; cin >> ratio;

	if (norh == 1)
		accArr[account_num++] = new NormalAccount(num, money, name, ratio);
	else
	{
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> sratio;
		accArr[account_num++] = new HighCreditAccount(num, money, name, ratio, sratio);
	}

	cout << endl << endl;
}

void AccountHandler::DepositMoney(void)
{
	int num, money;
	cout << "[입   금]" << endl;
	cout << "계좌ID : "; cin >> num;

	for (int i = 0; i < account_num; i++)
	{
		if (accArr[i]->get_accNum() == num)
		{
			cout << "입금액 : ";
			cin >> money;

			accArr[i]->plus_accMoney(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "올바르지 않은 ID입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int num, money;
	cout << "[출   금]" << endl;
	cout << "계좌ID : "; cin >> num;

	for (int i = 0; i < account_num; i++)
	{
		if (accArr[i]->get_accNum() == num)
		{
			cout << "출금액 : ";
			cin >> money;

			if (accArr[i]->get_accMoney() >= money)
			{
				accArr[i]->minus_accMoney(money);
				cout << "출금완료" << endl << endl;
				return;
			}
			cout << "잔액이 부족합니다." << endl << endl;
			return;
		}
	}
	cout << "올바르지 않은 ID입니다." << endl << endl;
}

void AccountHandler::PrintAllInfo(void)
{
	for (int i = 0; i < account_num; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler(void)
{
	for (int i = 0; i < account_num; i++)
	{
		delete accArr[i];
	}
}