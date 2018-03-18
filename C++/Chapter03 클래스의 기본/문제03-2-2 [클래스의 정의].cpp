#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
	private:
		char pri_Str[30];
		
	public:
		void SetString(char * strr);
		void ShowString(void);	
};

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}

void Printer::SetString(char * strr)
{
	strcpy(pri_Str, strr);
}

void Printer::ShowString(void)
{
	for(int i=0; i<strlen(pri_Str); i++)
	{	
		cout<<*(pri_Str+i);
	}
	cout<<endl;
}	
