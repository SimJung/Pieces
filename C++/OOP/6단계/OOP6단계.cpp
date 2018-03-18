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
		cout<<"계좌ID : "<<accNum<<endl;
		cout<<"이름 : "<<accName<<endl;
		cout<<"잔액 : "<<accMoney<<endl;
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
		cout<<"이자율 : "<<naratio<<endl; 
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
		cout<<"신용등급(1toA, 2toB, 3toC) : "<<specialRatio<<endl;
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
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입금"<<endl;
		cout<<"3. 출금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택 : ";
	}		
	
	void MakeAccount(void)
	{
		int num, money, norh, ratio, sratio;
		char name[20];
		
		cout<<"[계좌종류선택]"<<endl;
		cout<<"1.보통예금계좌	2.신용신뢰계좌"<<endl;
		cout<<"선택 : ";
		
		cin>>norh;
		
		if(norh == 1)
			cout<<"[보통예금계좌 개설]"<<endl;
		else if(norh == 2)
			cout<<"[신용신뢰계좌 개설]"<<endl;
			
		cout<<"계좌ID : "; cin>>num;
		cout<<"이름 : "; cin>>name;
		cout<<"입금액 : "; cin>>money;
		cout<<"이자율 : "; cin>>ratio;
		
		if(norh == 1)
			accArr[account_num++] = new NormalAccount(num, money, name, ratio);
		else
		{
			cout<<"신용등급(1toA, 2toB, 3toC): ";
			cin>>sratio;
			accArr[account_num++] = new HighCreditAccount(num, money, name, ratio, sratio);
		}
		
		cout<<endl<<endl;
	}
	
	void DepositMoney(void)
	{
		int num, money;
		cout<<"[입   금]"<<endl;
		cout<<"계좌ID : "; cin>>num;
		
		for(int i=0; i<account_num; i++)
		{
			if(accArr[i]->get_accNum() == num)
			{
				cout<<"입금액 : ";
				cin>>money;
				
				accArr[i]->plus_accMoney(money);
				cout<<"입금완료"<<endl<<endl;
				return ;
			}
		}
		
		cout<<"올바르지 않은 ID입니다."<<endl<<endl; 
	}
	
	void WithdrawMoney(void)
	{
		int num, money;
		cout<<"[출   금]"<<endl;
		cout<<"계좌ID : "; cin>>num;
		
		for(int i=0; i<account_num; i++)
		{
			if(accArr[i]->get_accNum() == num)
			{
				cout<<"출금액 : ";
				cin>>money;
				
				if(accArr[i]->get_accMoney() >= money)
				{
					accArr[i]->minus_accMoney(money);
					cout<<"출금완료"<<endl<<endl;
					return ;
				} 
				cout<<"잔액이 부족합니다."<<endl<<endl;
				return ; 
			}
		}
		cout<<"올바르지 않은 ID입니다."<<endl<<endl; 
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
				cout<<"프로그램을 종료합니다."<<endl;
				return 0;
				
			default:
				cout<<"잘못된 값입니다."<<endl<<endl;
		}
	}
	return 0;
}


