#include <iostream>
#define ARR_CAP 100000
using namespace std;

class List //List Ŭ���� ����
{
private:
	int arr[ARR_CAP] = { NULL, };
	int count; //�� data�� ����

public:
	List() : count(0) //constructor, default�� ���� �� count������ member initializer
	{
	}


	void InsertHead(int d) //head�� �����͸� �����ϴ� �Լ�
	{
		if (!count) //���� data�� �� ���� ���ٸ�
			arr[count] = d; //arr�� ù ���ҷ� �����Ѵ�

		else //data�� �ϳ��� �ִٸ�
		{
			for (int i = count; i > 0; i--) //�� ���� ������ŭ �ݺ��Ѵ�
				arr[i] = arr[i - 1]; //��� ���Ҹ� �� ĭ�� �ڷ� �δ�

			arr[0] = d; //arr�� ù ���ҷ� �����Ѵ�
		}

		++count; //�� ���� ������ �ϳ� �ø���
	}



	int Find(int d) //List���� �����͸� ã�Ƽ� index�� ��ȯ�ϴ� �Լ�
	{
		for (int i = 0; i < count; i++) //�� ���� ������ŭ �ݺ��Ѵ�
			if (arr[i] == d) //���� ã�� ���� ���Ұ� ��ġ�Ѵٸ�
				return i; //i�� ��ȯ�Ѵ�

		cout << -1 << endl; //ã�� ���ϸ� -1�� ����Ѵ�
		return -1; //-1�� ��ȯ�Ͽ� ã�� �������� �˸���
	}



	void InsertBefore(int fd, int id) //List���� �����͸� ã�� �� ������ �����ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1) //���� ã�� �����Ͱ� �ִٸ�
		{
			for (int i = count; i > temp; i--) //��ü ���� �������� ã�� index�� �� ��ŭ ����
				arr[i] = arr[i - 1]; //���ҵ��� �� ĭ�� �ڷ� �̷��

			arr[temp] = id; //�˻��� index�� ���� �����Ѵ�.
			++count; //�� ���� ������ �ϳ� �ø���.
		}
	}



	void InsertAfter(int fd, int id) //List���� �����͸� ã�� �� ���Ŀ� �����ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1) //���� ã�� �����Ͱ� �ִٸ�
		{
			for (int i = count; i > temp+1; i--) //��ü ���� �������� ã�� (index-1)�� �� ��ŭ ����
				arr[i] = arr[i - 1]; //���ҵ��� �� ĭ�� �ڷ� �̷��

			arr[temp + 1] = id; //�˻��� index�� ���� �����Ѵ�.
			++count; //�� ���� ������ �ϳ� �ø���.
		}
	}



	void Replace(int fd, int id) //List���� �����͸� ã�� ��ü�ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1) //���� ã�� �����Ͱ� �ִٸ�
			arr[temp] = id; //����� data�� �����Ѵ�.
	}



	void Erase(int fd) //List���� �����͸� ã�� �����ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1) //���� ã�� �����Ͱ� �ִٸ�
		{
			for (int i = temp; i < count; i++) //��ü ���� �������� ã�� index�� �� ��ŭ ����
				arr[i] = arr[i + 1]; //���ҵ��� �� ĭ�� ������ ����
			
			--count; //������ ������ �ϳ� ����.
		}
	}



	void Next(int fd) //List���� �����͸� ã�� ���� ���Ҹ� ����ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1 && temp != count - 1) //���� ã�� �����Ͱ� �ְ� ������ ���Ұ� �ƴ϶��
		{
			cout << arr[temp + 1] << endl; //���� ���Ҹ� ����Ѵ�
			return; //�Լ��� �����Ѵ�
		}
		else if (temp != -1 && temp == count - 1) //���� ������ �����͸� ����Ų�ٸ�
			cout << -1 << endl; //-1�� ����Ѵ�
			
	}



	void Previous(int fd) //List���� �����͸� ã�� ���� ���Ҹ� ����ϴ� �Լ�
	{
		int temp; //�˻��� index�� ������ ����
		if ((temp = Find(fd)) != -1 && temp != 0) //���� ã�� �����Ͱ� �ְ� ù��° ���Ұ� �ƴ϶��
		{
			cout << arr[temp - 1] << endl; //���� ���Ҹ� ����Ѵ�
			return; //�Լ��� �����Ѵ�
		}
		else if (temp != -1 && temp == 0) //���� ù��° �����͸� ����Ų�ٸ�
			cout << -1 << endl; //-1�� ����Ѵ�
	}


	void Print() //List�� ��� data�� ����ϴ� �Լ�
	{
		if (count) //���Ұ� �ϳ��� ���� ���
		{
			for (int i = 0; i < count; i++) //��ü ���� ������ŭ �ݺ��Ѵ�
				cout << arr[i] << ' '; //���Ҹ� ����Ѵ�
		}
		cout << endl; //�������� �����Ѵ�
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