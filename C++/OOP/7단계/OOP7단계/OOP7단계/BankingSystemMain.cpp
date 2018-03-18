#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler handler;
	int choice_Num;
	while (1)
	{
		handler.ShowMenu();
		cin >> choice_Num;
		cout << endl;

		switch (choice_Num)
		{
		case MAKE:
			handler.MakeAccount();
			break;

		case DEPOSIT:
			handler.DepositMoney();
			break;

		case WITHDRAW:
			handler.WithdrawMoney();
			break;

		case PRINT:
			handler.PrintAllInfo();
			break;

		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;

		default:
			cout << "�߸��� ���Դϴ�." << endl << endl;
		}
	}
	return 0;
}


