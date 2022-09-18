#include<iostream>

using namespace std;

int S[1001],dp1[1001],dp2[1001];
int A;

int main()
{
	cin >> A;

	for (int i = 0; i < A; i++)
		cin >> S[i];

	for (int i = 0; i < A; i++)
	{
		dp1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (S[i] > S[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for (int i = A - 1; i >= 0; i--)
	{
		dp2[i] = 1;
		for (int j = A-1; j >i; j--)
		{
			if (S[i] > S[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	int result = 0;
	for (int i = 0; i < A; i++)
		result = max(result, dp1[i] + dp2[i]);
	cout << result-1;
}