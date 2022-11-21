#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1;t <= T;t++)
	{
		int n, arr[11][11] = { 0, };
		cin >> n;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < i + 1;j++)
			{
				if (j == 0 || j == i) 
					arr[i][j] = 1;
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				}
			}
		}
		cout << "#" << t << "\n";
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (arr[i][j] == 0) break;
				cout << arr[i][j]<<" ";
			}
			cout << "\n";
		}
	}
}