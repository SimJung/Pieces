#include <iostream>
using namespace std;

class ParentException
{
public:
	virtual void ShowExceptionReason()=0;
};

class sonException : public ParentException
{
private:
	int num;
public:
	sonException(int n) : num(n) { }
	void ShowExceptionReason()
	{
		cout<<num<<"초과의 값을 입력하십시오."<<endl;
	}
};

class daughterException : public ParentException
{
private:
	int nn;
public:
	daughterException(int n) : nn(n) { }
	void ShowExceptionReason()
	{
		cout<<nn<<"원 만큼 잔액이 없습니다."<<endl;
	}
};

int main(void)
{
	int money = 10000, num;
	while(1)
	{
		cout<<"금액을 입력해주세요 : ";
		cin>>num;
		
		try
		{
			if(num <= 0)
			{
				sonException expn(num);
				throw expn;
			}
			//money += num;
			
			if(num > money)
			{
				daughterException expn(num);
				throw expn;
			}
			money -= num;
		}
		
		catch(sonException& expn)
		{
			expn.ShowExceptionReason();
		}
		
		catch(daughterException& expn)
		{
			expn.ShowExceptionReason();
		}		
		
		cout<<"잔액 : "<<money<<endl<<endl;
	}
	return 0;
}
