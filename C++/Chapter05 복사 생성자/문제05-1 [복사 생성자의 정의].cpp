#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

namespace COMP_POS
{
	enum{CLERK, SENIOR, ASSIST, MANAGER};
	
	void ShowCompInfo(int pos)
	{
		switch(pos)
		{
			case CLERK:
				cout<<"���"<<endl;
				break;
			case SENIOR:
				cout<<"����"<<endl;
				break;
			case ASSIST:
				cout<<"�븮"<<endl;
				break;
			case MANAGER:
				cout<<"����"<<endl;
				break; 
		}
		cout<<endl;

	}
}

class NameCard
{
private:
	char * name;
	char * company;
	char * phone;
	int position;
public:
	NameCard(char * na, char * co, char * ph, int po)
	{
		name = new char[strlen(na)];
		strcpy(name, na);
		
		company = new char[strlen(co)];
		strcpy(company, co);
		
		phone = new char[strlen(ph)];
		strcpy(phone, ph);
		
		position = po;
	}
	
	void ShowNameCardInfo(void)
	{
		cout<<"�̸� : "<<name<<endl;
		cout<<"ȸ�� : "<<company<<endl;
		cout<<"��ȭ��ȣ : "<<phone<<endl;
		cout<<"���� : "; 
		COMP_POS::ShowCompInfo(position);
	}
	
	~NameCard(void)
	{
		delete []name;
		delete []company;
		delete []phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}
