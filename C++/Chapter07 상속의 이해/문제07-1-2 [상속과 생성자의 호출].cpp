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
		cout<<"�̸� : "<<name<<endl;
		cout<<"���� : "<<age<<endl;
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
		cout<<"�ּ� : "<<addr<<endl;
		cout<<"��ȭ : "<<phone<<endl<<endl;
	}
	
	~MyFriendDetailInfo(void)
	{
		delete [] addr;
		delete [] phone;
	}
};

int main(void)
{
	MyFriendInfo chulsu("��ö��", 20);
	chulsu.ShowMyFriendInfo();
	
	cout<<endl;
	
	MyFriendDetailInfo minsu("��μ�", 28, "�㸮�� ���ñ� ������ �η�����", "010 - 2214 - 7982");
	minsu.ShowMyFriendDetailInfo();
	
	cout<<endl;
	
	minsu.ShowMyFriendInfo();
	return 0;
}
