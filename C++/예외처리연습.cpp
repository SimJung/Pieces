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
		cout<<num<<"�ʰ��� ���� �Է��Ͻʽÿ�."<<endl;
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
		cout<<nn<<"�� ��ŭ �ܾ��� �����ϴ�."<<endl;
	}
};

int main(void)
{
	int money = 10000, num;
	while(1)
	{
		cout<<"�ݾ��� �Է����ּ��� : ";
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
		
		cout<<"�ܾ� : "<<money<<endl<<endl;
	}
	return 0;
}
