#include <iostream>

using namespace std;

typedef struct __Account
{
	int accNum;
	int accMoney;
	string accName;
} Account;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void PrintAllInfo(void);

int account_Num = 0;
Account accArr[100];
enum {MAKE = 1, DEPOSIT, WITHDRAW,  PRINT, EXIT};

int main(void)
{
	int choice_Num;
	while(1)
	{
		ShowMenu();
		cin>>choice_Num;
		cout<<endl;
		
		switch(choice_Num)
		{
			case MAKE:
				MakeAccount();
				break;
				
			case DEPOSIT:
				DepositMoney();
				break;
				
			case WITHDRAW:
				WithdrawMoney();
				break;
				
			case PRINT:
				PrintAllInfo();
				break;
				
			case EXIT:
				cout<<"���α׷��� �����մϴ�."<<endl; 
				return 0;
				
			default:
				cout<<"�߸��� ���Դϴ�."<<endl<<endl;
				break; 
		}
	}
	
	return 0;
}

void ShowMenu(void)
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �Ա�"<<endl;
	cout<<"3. ���"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"���� : ";
}

void MakeAccount(void)
{
	int num, money;
	string name;
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID : "; cin>>num;
	cout<<"�̸� : "; cin>>name;
	cout<<"�Աݾ� : "; cin>>money; 
	
	cout<<endl<<endl;
	
	accArr[account_Num].accNum = num;
	accArr[account_Num].accName = name;
	accArr[account_Num].accMoney = money;
	
	account_Num++;
}

void DepositMoney(void)
{
	int num, money;
	cout<<"[��   ��]"<<endl;
	cout<<"����ID : "; cin>>num;
	
	for(int i=0; i<account_Num; i++)
	{
		if(accArr[i].accNum == num)
		{
			cout<<"�Աݾ� : ";
			cin>>money;
			
			accArr[i].accMoney += money;
			cout<<"�ԱݿϷ�"<<endl<<endl;
			return ;
		}
	}
	
	cout<<"�ùٸ��� ���� ID�Դϴ�."<<endl<<endl; 
}

void WithdrawMoney(void)
{
	int num, money;
	cout<<"[��   ��]"<<endl;
	cout<<"����ID : "; cin>>num;
	
	for(int i=0; i<account_Num; i++)
	{
		if(accArr[i].accNum == num)
		{
			cout<<"��ݾ� : ";
			cin>>money;
			
			if(accArr[i].accMoney >= money)
			{
				accArr[i].accMoney -= money;
				cout<<"��ݿϷ�"<<endl<<endl;
				return ;
			} 
			cout<<"�ܾ��� �����մϴ�."<<endl<<endl;
			return ; 
		}
	}
	cout<<"�ùٸ��� ���� ID�Դϴ�."<<endl<<endl; 
}

void PrintAllInfo(void)
{
	for(int i=0; i<account_Num; i++)
	{
		cout<<"����ID : "<<accArr[i].accNum<<endl;
		cout<<"�̸� : "<<accArr[i].accName<<endl;
		cout<<"�ܾ� : "<<accArr[i].accMoney<<endl<<endl;
	}
}
