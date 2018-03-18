#include <iostream>

using namespace std;

int main(void) {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cout << "Case#" << i + 1 << endl;

		int num, answer = 0, noe = 0, chk = 0;
		cin >> num;

		int *arr = new int[num];
		int **val = new int *[num];

		for (int j = 0; j < num; j++)
		{
			val[j] = new int[2];
			val[j][0] = -1;
			val[j][1] = 0;
		}

		for (int j = 0; j < num; j++) cin >> arr[j];

		for (int j = 0; j < num; j++)
		{
			for (int k = 0; k < num; k++)
			{
				if (val[j][0] == arr[k])
				{
					val[j][1]++;
					chk = 1;
				}
			}
			if (chk == 0)
			{
				val[j][0] = arr[j];
				val[j][1] = 1;
				noe++;
			}
		}

		for (int j = 0; j < num; j++) if (val[j][1] % 2) answer ^= val[j][0];

		cout << answer << endl;
	}
	return 0;
}