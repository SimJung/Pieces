#include <iostream>
#include <string>

using namespace std;

class url
{
private:
	string html;
	
public:
	url * head = NULL;
	url * tail = NULL;
	
	url(string h) : html(h) {}
	
	void ShowHtml(void) const
	{
		cout<<html<<endl;
	}
};

int main(void)
{
	string indi, str;
	url url1("http://www.acm.org/");
	url * uptr;
	
	while(indi != "QUIT")
	{
		cin>>indi;
		
		if(indi == "VISIT")
		{
			cin>>str;
			uptr = url1.tail;
			uptr
		}else if(indi == "BACK")
		{
			if()
			{
				wall--;
				cout<<urls[wall]<<endl;
			}else
				cout<<"Ignored"<<endl;
		}else if(indi == "FORWARD")
		{
			if(urls[wall + 1] != "")
			{
				wall++;
				cout<<urls[wall]<<endl;
			}else
				cout<<"Ignored"<<endl;
		}else if(indi == "QUIT")
			return 0;
	}
	
	return 0;
}
