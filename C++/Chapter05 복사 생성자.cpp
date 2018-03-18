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
				cout<<"사원"<<endl;
				break;
			case SENIOR:
				cout<<"주임"<<endl;
				break;
			case ASSIST:
				cout<<"대리"<<endl;
				break;
			case MANAGER:
				cout<<"과장"<<endl;
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
	
	NameCard(const NameCard &copy) : position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	
	void ShowNameCardInfo(void)
	{
		cout<<"이름 : "<<name<<endl;
		cout<<"회사 : "<<company<<endl;
		cout<<"전화번호 : "<<phone<<endl;
		cout<<"직급 : "; 
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
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}
