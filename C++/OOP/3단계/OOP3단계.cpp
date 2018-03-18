#include <iostream>
#include <cstring>

using namespace std;

class Account
{
private:
	int accNum;
	int accMoney;
	char * accName;
	
public:
	Account(int num, int money, char * name) : accNum(num), accMoney(money)
	{
		accName = new char[strlen(name) + 1];
		strcpy(accName, name);
	}
	
	Account(void) : accNum(0), accMoney(0)
	{
		strcpy(accName, "");
	}
	
	Account(const Account &copy) : accNum(copy.accNum), accMoney(copy.accMoney)
	{
		accName = new char[strlen(copy.accName) + 1];
		strcpy(accName, copy.accName);
	}
	
	~Account(void)
	{
		delete []accName;
	}
	
	void set_accNum(int n)
	{
		accNum = n;
	}
	
	int get_accNum(void)
	{
		return accNum;
	}
	
	void set_accMoney(int n)
	{
		accMoney = n;
	}
	
	void plus_accMoney(int n)
	{
		accMoney += n;
	}
	
	void minus_accMoney(int n)
	{
		accMoney -= n;
	}
	
	int get_accMoney(void)
	{
		return accMoney;
	}
	
	void set_accName(char * n)
	{
		accName = new char[strlen(n) + 1];
		strcpy(accName, n);
	}
	
	char * get_accName(void)
	{
		return accName;
	}
};

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void PrintAllInfo(void);

int account_Num = 0;
Account * accArr[100];
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
	for(int i=0; i<account_Num; i++)
	{
		delete accArr[i];
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
	char name[20];
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID : "; cin>>num;
	cout<<"�̸� : "; cin>>name;
	cout<<"�Աݾ� : "; cin>>money; 
	
	cout<<endl<<endl;
	
	accArr[account_Num] = new Account(num, money, name);
	
	account_Num++;
}

void DepositMoney(void)
{
	int num, money;
	cout<<"[��   ��]"<<endl;
	cout<<"����ID : "; cin>>num;
	
	for(int i=0; i<account_Num; i++)
	{
		if(accArr[i]->get_accNum() == num)
		{
			cout<<"�Աݾ� : ";
			cin>>money;
			
			accArr[i]->plus_accMoney(money);
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
		if(accArr[i]->get_accNum() == num)
		{
			cout<<"��ݾ� : ";
			cin>>money;
			
			if(accArr[i]->get_accMoney() >= money)
			{
				accArr[i]->minus_accMoney(money);
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
		cout<<"����ID : "<<accArr[i]->get_accNum()<<endl;
		cout<<"�̸� : "<<accArr[i]->get_accName()<<endl;
		cout<<"�ܾ� : "<<accArr[i]->get_accMoney()<<endl<<endl;
	}
}
