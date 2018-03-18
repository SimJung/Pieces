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
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		default:
			cout << "잘못된 값입니다." << endl << endl;
		}
	}
	return 0;
}


