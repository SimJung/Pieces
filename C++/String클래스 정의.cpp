#include <cstring> 
#include <iostream>
using namespace std;

class String
{
private:
	char * str;
	int len;
	
public:
	String()
	{
		len = 0;
		str = NULL;
	}
	
	String(const char * c) : len(strlen(c) + 1)
	{
		str = new char[len];
		strcpy(str, c);
	}
	
	String(const String& s) : len(s.getlen())
	{
		str = new char[len];
		strcpy(str, s.str);
	}
	
	String& operator= (const String& s)
	{
		if(str != NULL)
			delete []str;
		len = s.len;
		str = new char[len];
		strcpy(str, s.str);
		return *this;
	}
	
	String& operator+= (const String& s)
	{
		*this = *this + s;
		return *this;
	}
	
	bool operator== (const String& s)
	{
		return strcmp(str, s.str) ? false : true;
	}
	
	int getlen() const { return len; }
	
	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
	friend String operator+ (const String& s1, const String& s2);
	
	~String()
	{
		if(str != NULL)
			delete []str;
	}
};

String operator+ (const String& s1, const String& s2)
{
	char * cs = new char[s1.getlen() + s2.getlen() - 2];
	strcpy(cs, s1.str);
	strcat(cs, s2.str);
	String ss(cs);
	delete []cs;
	return ss;
}

ostream& operator<< (ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char ccc[100];
	is>>ccc;
	s = String(ccc);
	return is;
}

int main(void)
{
	String a("I am a star. ");
	String b = a;
	String c="And you are a moon. ";
	String d = a+c;
	String e;
	
	cout<<d.getlen()<<endl;
	cout<<b<<endl<<c<<endl;
	
	a += b;
	
	cout<<a<<endl<<d<<endl;
	
	cout<<(a == c)<<endl;
	
	cout<<"문자열을 입력하세요 : ";
	cin>>e;
	cout<<e<<endl;
	return 0;
}
