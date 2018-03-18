#include "AccountHandler.h"

AccountHandler::AccountHandler(void) : account_num(0) {}

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

void AccountHandler::MakeAccount(void)
{
	int num, money, norh, ratio, sratio;
	string name;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���	2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";

	cin >> norh;

	if (norh == 1)
		cout << "[���뿹�ݰ��� ����]" << endl;
	else if (norh == 2)
		cout << "[�ſ�ŷڰ��� ����]" << endl;

	cout << "����ID : "; cin >> num;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << "������ : "; cin >> ratio;

	if (norh == 1)
		accArr[account_num++] = new NormalAccount(num, money, name, ratio);
	else
	{
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> sratio;
		accArr[account_num++] = new HighCreditAccount(num, money, name, ratio, sratio);
	}

	cout << endl << endl;
}

void AccountHandler::DepositMoney(void)
{
	int num, money;
	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> num;

	for (int i = 0; i < account_num; i++)
	{
		if (accArr[i]->get_accNum() == num)
		{
			cout << "�Աݾ� : ";
			cin >> money;

			accArr[i]->plus_accMoney(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "�ùٸ��� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int num, money;
	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> num;

	for (int i = 0; i < account_num; i++)
	{
		if (accArr[i]->get_accNum() == num)
		{
			cout << "��ݾ� : ";
			cin >> money;

			if (accArr[i]->get_accMoney() >= money)
			{
				accArr[i]->minus_accMoney(money);
				cout << "��ݿϷ�" << endl << endl;
				return;
			}
			cout << "�ܾ��� �����մϴ�." << endl << endl;
			return;
		}
	}
	cout << "�ùٸ��� ���� ID�Դϴ�." << endl << endl;
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