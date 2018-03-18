#include <iostream>
using namespace std;

class Node ///Node 클래스 구현
{
private:
	int data; //node의 원소 타입은 integer형
	Node* next; //다음 node의 주솟값을 담을 포인터 변수
	Node* prev; //이전 node의 주솟값을 담을 포인터 변수

public:
	Node(int d = 0, Node* n = 0, Node* p = 0) //constructor 및 default값 설정
	{
		data = d; //data에 parameter d를 대입
		next = n; //next에 parameter n(주솟값)을 대입
		prev = p; //prev에 parameter p(주솟값)을 대입
	}

	friend class List; //friend로 설정하여 제한적인 private 멤버 접근을 허가함

};


class List //List 클래스 구현
{
private:
	Node* head; //가장 앞의 Node를 가리킬 포인터
	Node* tail; //가장 끝의 Node를 가리킬 포인터 
	int count; //총 Node의 개수

public:
	List(Node* h = 0, Node* t = 0) : count(0) //constructor, default값 설정 및 count변수의 member initializer
	{
		head = h;
		tail = t;
	}


	void InsertHead(int d) //head에 데이터를 삽입하는 함수
	{
		if (head == 0) //head가 가리키는 Node가 있을 때와 없을 때로 구분, head가 없을 때
		{
			head = new Node(d, 0, 0); //New 연산자를 이용, 새롭게 head를 할당
			tail = head->next;
		}
		
		else //head가 이미 있을 경우,
		{
			Node* temp = head; //head를 백업해둔 뒤
			head = new Node(d, temp, 0); //head를 새로운 Node로 설정해주고 그 next를 백업해둔 Node로 설정
			temp->prev = head; //이전 head의 prev로 새로운 head를 지정해준다

			if (count == 1) // 총 Node가 1개일 경우
				tail = temp; //이전 head를 tail로 설정한다
		}

		count++; //Node의 개수가 하나 늘어남
	}



	Node* Find(int d) //List에서 데이터를 찾아서 출력하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		for (temp = head; temp != 0; temp = temp->next) //head부터 next가 없을 때 까지 모든 Node를 방문
		{
			if (temp->data == d) //만약 temp의 data가 찾는 값일 경우
				return temp; //찾은 값을 반환한다
		}
			
		cout << -1 << endl; //못 찾았을 경우 -1 출력
		return 0;
	}



	void InsertBefore(int fd, int id) //List에서 데이터를 찾아 그 이전에 삽입하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if((temp = Find(fd)) != 0) //만약 찾을 Node가 존재한다면,
		{
			if (temp == head) //만약 temp가 head라면
				InsertHead(id); //InsertHead함수를 호출한다
				

			else //만약 temp가 head가 아니면
			{ 
				Node* newP = new Node(id, temp, temp->prev); //새로운 Node를 선언하고 data는 parameter, next는 검색한 node, prev는 검색한 node의 prev로 설정
				temp->prev = newP; //현재 Node의 이전 Node로 설정
				newP->prev->next = newP; //이전 Node의 다음 Node로 설정해준다
				count++; //Node의 개수를 하나 더한다.
			}

			return; //함수를 종료한다
		}
	}



	void InsertAfter(int fd, int id) //List에서 데이터를 찾아 그 이후에 삽입하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if ((temp = Find(fd)) != 0) //만약 찾을 Node가 존재한다면,
		{
			if (temp == tail) //만약 temp가 tail이면
			{
				Node* bu = tail; //tail을 백업해둔 뒤
				tail = new Node(id, 0, bu); //tail을 새로운 Node로 설정해주고 그 next를 백업해둔 Node로 설정
				bu->next = tail; //이전 tail의 Next로 설정해준다
			}


			else //만약 temp가 tail이 아니면
			{ 
				Node* newP = new Node(id, temp->next, temp); //새로운 Node를 선언하고 data는 parameter, next는 검색한 node의 next, prev는 검색한 node로 설정
				temp->next = newP; //현재 Node의 다음 Node로 설정한다
				newP->next->prev = newP; //다음 Node의 이전 Node로 설정한다
			}

			count++; //Node의 개수를 하나 더한다.
			return; //함수를 종료한다
		}
	}



	void Replace(int fd, int id) //List에서 데이터를 찾아 교체하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if ((temp = Find(fd)) != 0) //만약 찾을 Node가 존재한다면,
		{
			temp->data = id; //temp의 data를 parameter로 바꿔준다
			return; //함수를 종료한다
		}
	}



	void Erase(int fd) //List에서 데이터를 찾아 삭제하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if ((temp = Find(fd)) != 0) //만약 찾을 Node가 존재한다면,
		{
			if (temp == head) //temp가 head라면
			{
				temp->next->prev = temp->prev; //head는 prev가 없으니 temp의 다음 node의 prev를 temp의 이전 node로 설정해준다
				head = temp->next; //head를 지웠으니 다음 Node를 head로 설정
			}
				
			else if (temp == tail) //temp가 tail이라면
			{
				temp->prev->next = temp->next; //tail은 next가 없으니 temp의 이전 node의 next를 temp의 다음 node로 설정해준다
				tail = temp->prev; //tail을 지웠으니 이전 Node로 tail을 설정
			}
				
			else //temp가 둘 다 아니라면
			{
				temp->prev->next = temp->next; //temp의 이전 node의 next를 temp의 다음 node로 설정해준다
				temp->next->prev = temp->prev; //temp의 다음 node의 prev를 temp의 이전 node로 설정해준다
			}

			delete temp; //temp를 삭제
			return; //함수를 종료한다
		}
	}



	void Next(int fd) //List에서 데이터를 찾아 다음 원소를 출력하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if ((temp = Find(fd)) != 0 && temp->next != 0) //찾을 Node가 존재하고 temp가 tail이 아닐 경우
		{
			cout << temp->next->data << endl; //temp의 다음 Node의 data를 출력
			return; //함수를 종료한다
		}
			
		else if (temp != 0 && temp->next == 0)
		{
			cout << -1 << endl;
		}
	}



	void Previous(int fd) //List에서 데이터를 찾아 이전 원소를 출력하는 함수
	{
		Node* temp; //검색에 쓰일 Node형 포인터 변수

		if ((temp = Find(fd)) != 0 && temp->prev != 0) //찾을 Node가 존재하고 temp가 head가 아닐 경우
		{
			cout << temp->prev->data << endl; //temp의 다음 Node의 data를 출력
			return; //함수를 종료한다
		}
		else if (temp != 0 && temp->prev == 0)
		{
			cout << -1 << endl;
		}
			
	}


	void Print() //List의 모든 data를 출력하는 함수
	{
		if (head) //List가 비어있지 않다면
		{
			Node* temp; //검색에 쓰일 Node형 포인터 변수

			for (temp = head; temp != 0; temp = temp->next) //head부터 next가 없을 때 까지 모든 Node를 방문
				cout << temp->data << ' '; //temp의 data와 공백을 출력
		}
		cout << endl; //마지막은 개행한다.
	}
};

int main(void)
{
	int indi; //메뉴의 선택값
	List list; //list 객체 선언
	while (1)
	{
		cin >> indi; //매 반복마다 새롭게 메뉴를 선택할 수 있다
		int n1, n2; //각 함수들의 parameter
		switch (indi)
		{
		case 0: //0일 경우 프로그램 종료
			return 0;

		case 1: //각각의 케이스에 따라 알맞은 함수 호출
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
			cout << "입력이 유효하지 않습니다" << endl;
			break;
		}
	}

	return 0;
}