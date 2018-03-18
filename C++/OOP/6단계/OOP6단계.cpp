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
	
	virtual ~Account(void)
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
	
	virtual void plus_accMoney(int n)
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
	
	virtual void ShowAccInfo(void) const
	{
		cout<<"����ID : "<<accNum<<endl;
		cout<<"�̸� : "<<accName<<endl;
		cout<<"�ܾ� : "<<accMoney<<endl;
	}
};

class NormalAccount : public Account
{
private:
	int naratio;
public:
	NormalAccount(int num, int money, char * name, int ratio) : Account(num, money, name), naratio(ratio)
	{}
	
	int get_ratio() const
	{
		return naratio;
	}
	
	virtual void plus_accMoney(int n)
	{
		Account::plus_accMoney(n + (int)(Account::get_accMoney()*naratio/100.0));
	}
	
	virtual void ShowAccInfo(void) const
	{
		Account::ShowAccInfo();
		cout<<"������ : "<<naratio<<endl; 
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;
	
public:
	HighCreditAccount(int num, int money, char * name, int ratio, int sratio) : NormalAccount(num, money, name, ratio), specialRatio(sratio)
	{}
	
	virtual void plus_accMoney(int n)
	{
		switch(specialRatio)
		{
		case 0:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 7)/100.0));
			break;
		case 1:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 4)/100.0));
			break;
		case 2:
			Account::plus_accMoney(n + (int)(Account::get_accMoney()*(NormalAccount::get_ratio() + 2)/100.0));
			break;
		}	
		
	}
	
	virtual void ShowAccInfo(void) const
	{
		NormalAccount::ShowAccInfo();
		cout<<"�ſ���(1toA, 2toB, 3toC) : "<<specialRatio<<endl;
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
		int num, money, norh, ratio, sratio;
		char name[20];
		
		cout<<"[������������]"<<endl;
		cout<<"1.���뿹�ݰ���	2.�ſ�ŷڰ���"<<endl;
		cout<<"���� : ";
		
		cin>>norh;
		
		if(norh == 1)
			cout<<"[���뿹�ݰ��� ����]"<<endl;
		else if(norh == 2)
			cout<<"[�ſ�ŷڰ��� ����]"<<endl;
			
		cout<<"����ID : "; cin>>num;
		cout<<"�̸� : "; cin>>name;
		cout<<"�Աݾ� : "; cin>>money;
		cout<<"������ : "; cin>>ratio;
		
		if(norh == 1)
			accArr[account_num++] = new NormalAccount(num, money, name, ratio);
		else
		{
			cout<<"�ſ���(1toA, 2toB, 3toC): ";
			cin>>sratio;
			accArr[account_num++] = new HighCreditAccount(num, money, name, ratio, sratio);
		}
		
		cout<<endl<<endl;
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


