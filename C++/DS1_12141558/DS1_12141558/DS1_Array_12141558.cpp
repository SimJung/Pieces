#include <iostream>
#define ARR_CAP 100000
using namespace std;

class List //List 클래스 구현
{
private:
	int arr[ARR_CAP] = { NULL, };
	int count; //총 data의 개수

public:
	List() : count(0) //constructor, default값 설정 및 count변수의 member initializer
	{
	}


	void InsertHead(int d) //head에 데이터를 삽입하는 함수
	{
		if (!count) //만약 data가 한 개도 없다면
			arr[count] = d; //arr의 첫 원소로 설정한다

		else //data가 하나라도 있다면
		{
			for (int i = count; i > 0; i--) //총 원소 개수만큼 반복한다
				arr[i] = arr[i - 1]; //모든 원소를 한 칸씩 뒤로 민다

			arr[0] = d; //arr의 첫 원소로 설정한다
		}

		++count; //총 원소 개수를 하나 늘린다
	}



	int Find(int d) //List에서 데이터를 찾아서 index를 반환하는 함수
	{
		for (int i = 0; i < count; i++) //총 원소 개수만큼 반복한다
			if (arr[i] == d) //만약 찾는 값과 원소가 일치한다면
				return i; //i를 반환한다

		cout << -1 << endl; //찾지 못하면 -1을 출력한다
		return -1; //-1을 반환하여 찾지 못했음을 알린다
	}



	void InsertBefore(int fd, int id) //List에서 데이터를 찾아 그 이전에 삽입하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1) //만약 찾는 데이터가 있다면
		{
			for (int i = count; i > temp; i--) //전체 원소 개수에서 찾은 index를 뺀 만큼 실행
				arr[i] = arr[i - 1]; //원소들을 한 칸씩 뒤로 미룬다

			arr[temp] = id; //검색한 index에 값을 삽입한다.
			++count; //총 원소 개수를 하나 늘린다.
		}
	}



	void InsertAfter(int fd, int id) //List에서 데이터를 찾아 그 이후에 삽입하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1) //만약 찾는 데이터가 있다면
		{
			for (int i = count; i > temp+1; i--) //전체 원소 개수에서 찾은 (index-1)을 뺀 만큼 실행
				arr[i] = arr[i - 1]; //원소들을 한 칸씩 뒤로 미룬다

			arr[temp + 1] = id; //검색한 index에 값을 삽입한다.
			++count; //총 원소 개수를 하나 늘린다.
		}
	}



	void Replace(int fd, int id) //List에서 데이터를 찾아 교체하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1) //만약 찾는 데이터가 있다면
			arr[temp] = id; //저장된 data를 변경한다.
	}



	void Erase(int fd) //List에서 데이터를 찾아 삭제하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1) //만약 찾는 데이터가 있다면
		{
			for (int i = temp; i < count; i++) //전체 원소 개수에서 찾은 index를 뺀 만큼 실행
				arr[i] = arr[i + 1]; //원소들을 한 칸씩 앞으로 당긴다
			
			--count; //원소의 개수를 하나 뺀다.
		}
	}



	void Next(int fd) //List에서 데이터를 찾아 다음 원소를 출력하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1 && temp != count - 1) //만약 찾는 데이터가 있고 마지막 원소가 아니라면
		{
			cout << arr[temp + 1] << endl; //다음 원소를 출력한다
			return; //함수를 종료한다
		}
		else if (temp != -1 && temp == count - 1) //만약 마지막 데이터를 가리킨다면
			cout << -1 << endl; //-1을 출력한다
			
	}



	void Previous(int fd) //List에서 데이터를 찾아 이전 원소를 출력하는 함수
	{
		int temp; //검색한 index를 저장할 변수
		if ((temp = Find(fd)) != -1 && temp != 0) //만약 찾는 데이터가 있고 첫번째 원소가 아니라면
		{
			cout << arr[temp - 1] << endl; //이전 원소를 출력한다
			return; //함수를 종료한다
		}
		else if (temp != -1 && temp == 0) //만약 첫번째 데이터를 가리킨다면
			cout << -1 << endl; //-1을 출력한다
	}


	void Print() //List의 모든 data를 출력하는 함수
	{
		if (count) //원소가 하나라도 있을 경우
		{
			for (int i = 0; i < count; i++) //전체 원소 개수만큼 반복한다
				cout << arr[i] << ' '; //원소를 출력한다
		}
		cout << endl; //마지막은 개행한다
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