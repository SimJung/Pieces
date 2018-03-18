#include <iostream>
using namespace std;

class Node ///Node Ŭ���� ����
{
private:
	int data; //node�� ���� Ÿ���� integer��
	Node* next; //���� node�� �ּڰ��� ���� ������ ����
	Node* prev; //���� node�� �ּڰ��� ���� ������ ����

public:
	Node(int d = 0, Node* n = 0, Node* p = 0) //constructor �� default�� ����
	{
		data = d; //data�� parameter d�� ����
		next = n; //next�� parameter n(�ּڰ�)�� ����
		prev = p; //prev�� parameter p(�ּڰ�)�� ����
	}

	friend class List; //friend�� �����Ͽ� �������� private ��� ������ �㰡��

};


class List //List Ŭ���� ����
{
private:
	Node* head; //���� ���� Node�� ����ų ������
	Node* tail; //���� ���� Node�� ����ų ������ 
	int count; //�� Node�� ����

public:
	List(Node* h = 0, Node* t = 0) : count(0) //constructor, default�� ���� �� count������ member initializer
	{
		head = h;
		tail = t;
	}


	void InsertHead(int d) //head�� �����͸� �����ϴ� �Լ�
	{
		if (head == 0) //head�� ����Ű�� Node�� ���� ���� ���� ���� ����, head�� ���� ��
		{
			head = new Node(d, 0, 0); //New �����ڸ� �̿�, ���Ӱ� head�� �Ҵ�
			tail = head->next;
		}
		
		else //head�� �̹� ���� ���,
		{
			Node* temp = head; //head�� ����ص� ��
			head = new Node(d, temp, 0); //head�� ���ο� Node�� �������ְ� �� next�� ����ص� Node�� ����
			temp->prev = head; //���� head�� prev�� ���ο� head�� �������ش�

			if (count == 1) // �� Node�� 1���� ���
				tail = temp; //���� head�� tail�� �����Ѵ�
		}

		count++; //Node�� ������ �ϳ� �þ
	}



	Node* Find(int d) //List���� �����͸� ã�Ƽ� ����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		for (temp = head; temp != 0; temp = temp->next) //head���� next�� ���� �� ���� ��� Node�� �湮
		{
			if (temp->data == d) //���� temp�� data�� ã�� ���� ���
				return temp; //ã�� ���� ��ȯ�Ѵ�
		}
			
		cout << -1 << endl; //�� ã���� ��� -1 ���
		return 0;
	}



	void InsertBefore(int fd, int id) //List���� �����͸� ã�� �� ������ �����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if((temp = Find(fd)) != 0) //���� ã�� Node�� �����Ѵٸ�,
		{
			if (temp == head) //���� temp�� head���
				InsertHead(id); //InsertHead�Լ��� ȣ���Ѵ�
				

			else //���� temp�� head�� �ƴϸ�
			{ 
				Node* newP = new Node(id, temp, temp->prev); //���ο� Node�� �����ϰ� data�� parameter, next�� �˻��� node, prev�� �˻��� node�� prev�� ����
				temp->prev = newP; //���� Node�� ���� Node�� ����
				newP->prev->next = newP; //���� Node�� ���� Node�� �������ش�
				count++; //Node�� ������ �ϳ� ���Ѵ�.
			}

			return; //�Լ��� �����Ѵ�
		}
	}



	void InsertAfter(int fd, int id) //List���� �����͸� ã�� �� ���Ŀ� �����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if ((temp = Find(fd)) != 0) //���� ã�� Node�� �����Ѵٸ�,
		{
			if (temp == tail) //���� temp�� tail�̸�
			{
				Node* bu = tail; //tail�� ����ص� ��
				tail = new Node(id, 0, bu); //tail�� ���ο� Node�� �������ְ� �� next�� ����ص� Node�� ����
				bu->next = tail; //���� tail�� Next�� �������ش�
			}


			else //���� temp�� tail�� �ƴϸ�
			{ 
				Node* newP = new Node(id, temp->next, temp); //���ο� Node�� �����ϰ� data�� parameter, next�� �˻��� node�� next, prev�� �˻��� node�� ����
				temp->next = newP; //���� Node�� ���� Node�� �����Ѵ�
				newP->next->prev = newP; //���� Node�� ���� Node�� �����Ѵ�
			}

			count++; //Node�� ������ �ϳ� ���Ѵ�.
			return; //�Լ��� �����Ѵ�
		}
	}



	void Replace(int fd, int id) //List���� �����͸� ã�� ��ü�ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if ((temp = Find(fd)) != 0) //���� ã�� Node�� �����Ѵٸ�,
		{
			temp->data = id; //temp�� data�� parameter�� �ٲ��ش�
			return; //�Լ��� �����Ѵ�
		}
	}



	void Erase(int fd) //List���� �����͸� ã�� �����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if ((temp = Find(fd)) != 0) //���� ã�� Node�� �����Ѵٸ�,
		{
			if (temp == head) //temp�� head���
			{
				temp->next->prev = temp->prev; //head�� prev�� ������ temp�� ���� node�� prev�� temp�� ���� node�� �������ش�
				head = temp->next; //head�� �������� ���� Node�� head�� ����
			}
				
			else if (temp == tail) //temp�� tail�̶��
			{
				temp->prev->next = temp->next; //tail�� next�� ������ temp�� ���� node�� next�� temp�� ���� node�� �������ش�
				tail = temp->prev; //tail�� �������� ���� Node�� tail�� ����
			}
				
			else //temp�� �� �� �ƴ϶��
			{
				temp->prev->next = temp->next; //temp�� ���� node�� next�� temp�� ���� node�� �������ش�
				temp->next->prev = temp->prev; //temp�� ���� node�� prev�� temp�� ���� node�� �������ش�
			}

			delete temp; //temp�� ����
			return; //�Լ��� �����Ѵ�
		}
	}



	void Next(int fd) //List���� �����͸� ã�� ���� ���Ҹ� ����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if ((temp = Find(fd)) != 0 && temp->next != 0) //ã�� Node�� �����ϰ� temp�� tail�� �ƴ� ���
		{
			cout << temp->next->data << endl; //temp�� ���� Node�� data�� ���
			return; //�Լ��� �����Ѵ�
		}
			
		else if (temp != 0 && temp->next == 0)
		{
			cout << -1 << endl;
		}
	}



	void Previous(int fd) //List���� �����͸� ã�� ���� ���Ҹ� ����ϴ� �Լ�
	{
		Node* temp; //�˻��� ���� Node�� ������ ����

		if ((temp = Find(fd)) != 0 && temp->prev != 0) //ã�� Node�� �����ϰ� temp�� head�� �ƴ� ���
		{
			cout << temp->prev->data << endl; //temp�� ���� Node�� data�� ���
			return; //�Լ��� �����Ѵ�
		}
		else if (temp != 0 && temp->prev == 0)
		{
			cout << -1 << endl;
		}
			
	}


	void Print() //List�� ��� data�� ����ϴ� �Լ�
	{
		if (head) //List�� ������� �ʴٸ�
		{
			Node* temp; //�˻��� ���� Node�� ������ ����

			for (temp = head; temp != 0; temp = temp->next) //head���� next�� ���� �� ���� ��� Node�� �湮
				cout << temp->data << ' '; //temp�� data�� ������ ���
		}
		cout << endl; //�������� �����Ѵ�.
	}
};

int main(void)
{
	int indi; //�޴��� ���ð�
	List list; //list ��ü ����
	while (1)
	{
		cin >> indi; //�� �ݺ����� ���Ӱ� �޴��� ������ �� �ִ�
		int n1, n2; //�� �Լ����� parameter
		switch (indi)
		{
		case 0: //0�� ��� ���α׷� ����
			return 0;

		case 1: //������ ���̽��� ���� �˸��� �Լ� ȣ��
			cin >> n1;
			list.InsertHead(n1);
			break;

		case 2:
			cin >> n1;
			list.Find(n1);
			break;

		case 3:
			cin >> n1 >> n2;
			list.InsertBefore(n1, n2);
			break;

		case 4:
			cin >> n1 >> n2;
			list.InsertAfter(n1, n2);
			break;

		case 5:
			cin >> n1 >> n2;
			list.Replace(n1, n2);
			break;

		case 6:
			cin >> n1;
			list.Erase(n1);
			break;

		case 7:
			cin >> n1;
			list.Next(n1);
			break;

		case 8:
			cin >> n1;
			list.Previous(n1);
			break;

		case 9:
			list.Print();
			break;

		default:
			cout << "�Է��� ��ȿ���� �ʽ��ϴ�" << endl;
			break;
		}
	}

	return 0;
}