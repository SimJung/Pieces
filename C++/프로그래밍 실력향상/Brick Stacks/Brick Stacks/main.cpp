#include <iostream>

using namespace std;

int main(void)
{
	int num, k = 1;
	while (cin >> num)
	{
		if (num == 0)
			break;

		int sum = 0, answer = 0;
		int *arr = new int[num];

		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
			
			sum += arr[i];
		}

		sum /= num;

		for (int i = 0; i < num; i++)
		{
			if (arr[i] > sum)
				answer += arr[i] - sum;
		}

		cout << "Set #" << k << endl;
		cout << "The minimum number of moves is " << answer << "." << endl;

		k++;
	}
	return 0;
}