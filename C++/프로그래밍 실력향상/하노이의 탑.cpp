#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char temp);
double count = 0;
int main(void)
{
	int num;
	printf("옮길 원판의 갯수를 입력하시오 (1~64) : ");
	scanf("%d", &num);
	hanoi(num, 'A', 'C', 'B');
	printf("원판의 갯수는 %d개 이고, 옮긴 횟수는 %g번 입니다. \n", num, count);
	return 0;
}
void hanoi(int n, char from, char to, char temp)
{
	count++;
	if ( n == 1 ) {
		printf("원판 1 을 %c 에서 %c 로 이동합니다. \n", from, to); 
	} else {
		hanoi(n-1, from, temp, to);
		printf("원판 %d 을 %c 에서 %c 로 이동합니다. \n", n, from, to);
		hanoi(n-1, temp, to, from);
	}
}
