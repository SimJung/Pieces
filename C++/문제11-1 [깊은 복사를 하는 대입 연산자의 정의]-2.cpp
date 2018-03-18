#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book() : price(0)
	{
		title = NULL;
		isbn = NULL;
	}
	Book(char * ti, char * is, int pr) : price(pr)
	{
		title = new char [strlen(ti) + 1];
		strcpy(title, ti);
		
		isbn = new char [strlen(is) + 1];
		strcpy(isbn, is);
	}
	
	Book(Book& ref) : price(ref.price)
	{
		if(title != NULL)
		{
			cout<<"��������� �� title �� ����"<<endl;
			delete []title;	
		}	
		title = new char [strlen(ref.title) + 1];
		strcpy(title, ref.title);
		
		if(isbn != NULL)
		{
			cout<<"��������� �� isbn �� ����"<<endl;
			delete []isbn;	
		}	
		isbn = new char [strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	
	Book& operator=(const Book& ref)
	{
		price = ref.price;
		if(title != NULL)
		{
			cout<<"���Կ����� �� title �� ����"<<endl;
			delete []title;	
		}	
		title = new char [strlen(ref.title) + 1];
		strcpy(title, ref.title);
		
		if(isbn != NULL)
		{
			cout<<"���Կ����� �� isbn �� ����"<<endl;
			delete []isbn;	
		}	
		isbn = new char [strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	
	void ShowBookInfo() const
	{
		cout<<"���� : "<<title<<endl;
		cout<<"isbn : "<<isbn<<endl;
		cout<<"���� : "<<price<<endl;
	}
	
	~Book()
	{
		delete []title;
		delete []isbn;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;
public:
	EBook()
	{
		DRMKey = NULL;
	}
	
	EBook(char * ti, char * is, int pr, char * dr) : Book(ti, is, pr)
	{
		DRMKey = new char [strlen(dr) + 1];
		strcpy(DRMKey, dr);
	}
	
	EBook(EBook& ref) : Book(ref)
	{
		if(DRMKey != NULL)
		{
			cout<<"��������� �� DRMKey �� ����"<<endl;
			delete []DRMKey;	
		}	
		DRMKey = new char [strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		if(DRMKey != NULL)
		{
			cout<<"���Կ����� �� title �� ����"<<endl;
			delete []DRMKey;	
		}	
		DRMKey = new char [strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	
	void ShowBookInfo() const
	{
		Book::ShowBookInfo();
		cout<<"���� Ű : "<<DRMKey<<endl;
	}
	
	~EBook()
	{
		delete []DRMKey;
	}
};

int main(void)
{
	Book a("�ö����� ǥ����", "LOVE123", 10000);
	Book b(",",",",0);
	b = a;
	b.ShowBookInfo();
	
	EBook c("�Ƹ������ڷ����� ����", "MISS321", 20000, "a1b2c3d4e5");
	EBook d;
	d = c;
	d.ShowBookInfo();
	
	b = d;
	b.ShowBookInfo();
	
	return 0;
}
