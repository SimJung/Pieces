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
			cout<<"복사생성자 내 title 값 삭제"<<endl;
			delete []title;	
		}	
		title = new char [strlen(ref.title) + 1];
		strcpy(title, ref.title);
		
		if(isbn != NULL)
		{
			cout<<"복사생성자 내 isbn 값 삭제"<<endl;
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
			cout<<"대입연산자 내 title 값 삭제"<<endl;
			delete []title;	
		}	
		title = new char [strlen(ref.title) + 1];
		strcpy(title, ref.title);
		
		if(isbn != NULL)
		{
			cout<<"대입연산자 내 isbn 값 삭제"<<endl;
			delete []isbn;	
		}	
		isbn = new char [strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	
	void ShowBookInfo() const
	{
		cout<<"제목 : "<<title<<endl;
		cout<<"isbn : "<<isbn<<endl;
		cout<<"가격 : "<<price<<endl;
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
			cout<<"복사생성자 내 DRMKey 값 삭제"<<endl;
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
			cout<<"대입연산자 내 title 값 삭제"<<endl;
			delete []DRMKey;	
		}	
		DRMKey = new char [strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	
	void ShowBookInfo() const
	{
		Book::ShowBookInfo();
		cout<<"보안 키 : "<<DRMKey<<endl;
	}
	
	~EBook()
	{
		delete []DRMKey;
	}
};

int main(void)
{
	Book a("플라톤의 표류기", "LOVE123", 10000);
	Book b(",",",",0);
	b = a;
	b.ShowBookInfo();
	
	EBook c("아리스토텔레스의 모험", "MISS321", 20000, "a1b2c3d4e5");
	EBook d;
	d = c;
	d.ShowBookInfo();
	
	b = d;
	b.ShowBookInfo();
	
	return 0;
}
