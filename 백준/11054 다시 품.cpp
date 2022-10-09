#include <iostream>

using namespace std;
int A[1001], N, dpa[1001], dpb[1001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
	{
		dpa[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
				dpa[i] = max(dpa[j] + 1, dpa[i]);
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		dpb[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (A[j] < A[i])
				dpb[i] = max(dpb[i], dpb[j] + 1);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
		result = max(dpa[i] + dpb[i] - 1, result);
	cout << result;
	
}