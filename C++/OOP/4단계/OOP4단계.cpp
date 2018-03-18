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
	static int account_num;

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
};

int Account::account_num = 0;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void PrintAllInfo(void);

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
				cout<<"프로그램을 종료합니다."<<endl; 
				return 0;
				
			default:
				cout<<"잘못된 값입니다."<<endl<<endl;
				break; 
		}
	}
	for(int i=0; i<Account::account_num; i++)
	{
		delete accArr[i];
	}
	return 0;
}

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
	int num, money;
	char name[20];
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID : "; cin>>num;
	cout<<"이름 : "; cin>>name;
	cout<<"입금액 : "; cin>>money; 
	
	cout<<endl<<endl;
	
	accArr[Account::account_num] = new Account(num, money, name);
	
	Account::account_num++;
}

void DepositMoney(void)
{
	int num, money;
	cout<<"[입   금]"<<endl;
	cout<<"계좌ID : "; cin>>num;
	
	for(int i=0; i<Account::account_num; i++)
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
	
	for(int i=0; i<Account::account_num; i++)
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
	for(int i=0; i<Account::account_num; i++)
	{
		cout<<"계좌ID : "<<accArr[i]->get_accNum()<<endl;
		cout<<"이름 : "<<accArr[i]->get_accName()<<endl;
		cout<<"잔액 : "<<accArr[i]->get_accMoney()<<endl<<endl;
	}
}
