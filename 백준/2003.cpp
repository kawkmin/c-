#include<iostream>

using namespace std;

int N, M,cnt=0;
int A[10001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		int sum = A[i];
		if (sum == M)
		{
			cnt++;
		}
		else
		{
			for (int j = i + 1; j < N; j++)
			{
				sum += A[j];
				if (sum == M)
				{
					cnt++;
					break;
				}
				else if (sum > M)
					break;
			}
		}
	}
	cout << cnt;
}