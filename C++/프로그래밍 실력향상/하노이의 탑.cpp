#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char temp);
double count = 0;
int main(void)
{
	int num;
	printf("�ű� ������ ������ �Է��Ͻÿ� (1~64) : ");
	scanf("%d", &num);
	hanoi(num, 'A', 'C', 'B');
	printf("������ ������ %d�� �̰�, �ű� Ƚ���� %g�� �Դϴ�. \n", num, count);
	return 0;
}
void hanoi(int n, char from, char to, char temp)
{
	count++;
	if ( n == 1 ) {
		printf("���� 1 �� %c ���� %c �� �̵��մϴ�. \n", from, to); 
	} else {
		hanoi(n-1, from, temp, to);
		printf("���� %d �� %c ���� %c �� �̵��մϴ�. \n", n, from, to);
		hanoi(n-1, temp, to, from);
	}
}
