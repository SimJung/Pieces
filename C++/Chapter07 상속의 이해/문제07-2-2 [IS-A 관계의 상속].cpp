#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private :
	char * title;
	char * isbn;
	int price;
	
public:
	Book(char * ti, char * is, int pr) : price(pr)
	{
		title = new char[strlen(ti) + 1];
		isbn = new char[strlen(is) + 1];
		
		strcpy(title, ti);
		strcpy(isbn, is);
	}
	
	void ShowBookInfo(void) const
	{
		cout<<"���� : "<<title<<endl;
		cout<<"ISBN : "<<isbn<<endl;
		cout<<"���� : "<<price<<endl; 
	}
	
	~Book(void)
	{
		delete [] title;
		delete [] isbn;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;
	
public:
	EBook(char * ti, char * is, int pr, char * dr) : Book(ti, is, pr)
	{
		DRMKey = new char[strlen(dr) + 1];
		
		strcpy(DRMKey, dr);
	}
	
	void ShowEBookInfo(void) const
	{
		ShowBookInfo();
		cout<<"����Ű : "<<DRMKey<<endl;
	}
	
	~EBook(void)
	{
		delete [] DRMKey;
	}
};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	
	cout<<endl;
	
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "f18e1a21cz0v");
	ebook.ShowEBookInfo();
	
	
	
	return 0;
}
