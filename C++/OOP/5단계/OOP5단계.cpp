#include <iostream>
#include <cstring>

using namespace std;


enum {MAKE = 1, DEPOSIT, WITHDRAW,  PRINT, EXIT};

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
	
	int get_accNum(void) const
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
	
	int get_accMoney(void) const
	{
		return accMoney;
	}
	
	void set_accName(char * n)
	{
		accName = new char[strlen(n) + 1];
		strcpy(accName, n);
	}
	
	char * get_accName(void) const
	{
		return accName;
	}
	
	void ShowAccInfo(void) const
	{
		cout<<"����ID : "<<accNum<<endl;
		cout<<"�̸� : "<<accName<<endl;
		cout<<"�ܾ� : "<<accMoney<<endl;
	}
};



class AccountHandler
{
private:
	Account * accArr[100];
	int account_num;
	
public:
	AccountHandler(void) : account_num(0) {}
	
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
		
		accArr[account_num] = new Account(num, money, name);
		
		account_num++;
	}
	
	void DepositMoney(void)
	{
		int num, money;
		cout<<"[��   ��]"<<endl;
		cout<<"����ID : "; cin>>num;
		
		for(int i=0; i<account_num; i++)
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
		
		for(int i=0; i<account_num; i++)
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
		for(int i=0; i<account_num; i++)
		{
			accArr[i]->ShowAccInfo();
			cout<<endl;
		}
	}
	
	~AccountHandler(void)
	{
		for(int i=0; i<account_num; i++)
		{
			delete accArr[i];
		}
	}
};

int main(void)
{
	AccountHandler handler;
	int choice_Num;
	while(1)
	{
		handler.ShowMenu();
		cin>>choice_Num;
		cout<<endl;
		
		switch(choice_Num)
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
				cout<<"���α׷��� �����մϴ�."<<endl;
				return 0;
				
			default:
				cout<<"�߸��� ���Դϴ�."<<endl<<endl;
		}
	}
	return 0;
}


