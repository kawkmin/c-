#include<iostream>
#include<algorithm>
using namespace std;

int minu(int a[],int n) //모든 경우를 생각해서 복잡하게 함. 좀 더 쉬운 알고리즘 찾기
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 0) result++;
		else return result;
	}
	return result;
}

int main()
{
	int N,a[50],c[50],x=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a, a+N);
	int min = minu(a, N);
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] <= 0)
		{
			result++;
		}
		else
		{
			x = i - 1;
			continue;
		}
	}
	if (N % 2 == 0) //수열이 짝
	{
		if (min % 2 == 0) //마이너스 개수가 짝
		{
			for (int i = 0; i < N; i+=2)
			{
				result += a[i] * a[i + 1];
			}
		}
		else //마이너스 개수가 홀
		{

		}
	}
	else //수열이 홀
	{
		if (min % 2 == 0) //마이너스 개수가  짝
		{
			result += a[x];
			a[x] = -10001;
			sort(a, a + N - 1);
			for (int i = 1; i < N; i += 2)
			{
				result += a[i] * a[i + 1];
			}
		}
		else //마이너스 개수가 홀
		{

		}
	}
	cout << result;
}