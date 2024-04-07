#include <iostream>

using namespace std;

void show(int *arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int M;
	cin >> M;

	int N = 4;
	int *arr = new int[N]{0, 101, 5, 12};

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; i++)
		{
			if (arr[j] > 10)
				arr[j] /= 10;
		}
	}

	cout << arr[0] << " " << arr[1];
}