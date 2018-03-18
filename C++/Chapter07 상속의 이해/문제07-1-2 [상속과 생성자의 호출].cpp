#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(char * na, int ag) : age(ag)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	
	void ShowMyFriendInfo(void)
	{
		cout<<"이름 : "<<name<<endl;
		cout<<"나이 : "<<age<<endl;
	}
	
	~MyFriendInfo(void)
	{
		delete [] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char * na, int ag, char * ad, char * ph) : MyFriendInfo(na, ag)
	{
		addr = new char[strlen(ad) + 1];
		strcpy(addr, ad);
		
		phone = new char[strlen(ph) + 1];
		strcpy(phone, ph);
	}
	
	void ShowMyFriendDetailInfo(void)
	{
		ShowMyFriendInfo();
		cout<<"주소 : "<<addr<<endl;
		cout<<"전화 : "<<phone<<endl<<endl;
	}
	
	~MyFriendDetailInfo(void)
	{
		delete [] addr;
		delete [] phone;
	}
};

int main(void)
{
	MyFriendInfo chulsu("김철수", 20);
	chulsu.ShowMyFriendInfo();
	
	cout<<endl;
	
	MyFriendDetailInfo minsu("고민수", 28, "허리도 가늘군 만지면 부러지리", "010 - 2214 - 7982");
	minsu.ShowMyFriendDetailInfo();
	
	cout<<endl;
	
	minsu.ShowMyFriendInfo();
	return 0;
}
