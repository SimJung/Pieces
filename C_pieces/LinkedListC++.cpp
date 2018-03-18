#include <iostream>

using namespace std;

template <typename T>
class node
{
private:
	T data;
	node* next;
	
public:
	node()
	{
		data = 0;
		next = NULL;
	}
	
	node(T d)
	{
		data = d;
		next = NULL;
	}
	
	void setData(T d)
	{
		data = d;
	}
	
	void setNext(node* n)
	{
		next = n;
	}
	
	T getData()
	{
		return data;
	}
	
	node* getNext()
	{
		return next;
	}
	
	~node()
	{
		delete next;
		cout<<"Called destructor of data "<<data<<endl;
	}
};

template <typename T>
class List
{
private:
	node<T>* head;
	node<T>* temp;
	node<T>* tail;
	int count;
	
public:
	List()
	{
		head = new node<T>;
		temp = NULL;
		tail = NULL;
		head->setNext(tail);
		count = 1;
	}
	
	void push(T data)
	{
		temp = head;
		while(temp->getNext() != NULL)
			temp = temp->getNext();
		
		temp->setNext(new node<T>);
		temp = temp->getNext();
		temp->setData(data);
		temp->setNext(NULL);
		tail = temp;
		count++;
		
		cout<<"push Finished."<<endl;
	}
	
	void print()
	{
		temp = head;
		int num = 1;
		while(temp != NULL)
		{
			cout<<"data"<<num<<" : "<<temp->getData()<<endl;
			temp = temp->getNext();
			num++;
		}
		cout<<"print Finished"<<endl;
	}
	
	void insert(T data, int wall)
	{
		
	}
	
	void delete_list(node<T>* no)
	{
		if(no->getNext() != NULL)
			delete_list(no->getNext());
			
		else
			delete no;
	}
	
	~List()
	{
		delete_list(head);
		cout<<"Called destructor of list object"<<endl;
	}
};

int main(void)
{
	List<int> list;
	list.push(5);
	list.print();
	return 0;
}
