#include<iostream>
#include<algorithm>
using namespace std;

int minu(int a[],int n) //��� ��츦 �����ؼ� �����ϰ� ��. �� �� ���� �˰��� ã��
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
	if (N % 2 == 0) //������ ¦
	{
		if (min % 2 == 0) //���̳ʽ� ������ ¦
		{
			for (int i = 0; i < N; i+=2)
			{
				result += a[i] * a[i + 1];
			}
		}
		else //���̳ʽ� ������ Ȧ
		{

		}
	}
	else //������ Ȧ
	{
		if (min % 2 == 0) //���̳ʽ� ������  ¦
		{
			result += a[x];
			a[x] = -10001;
			sort(a, a + N - 1);
			for (int i = 1; i < N; i += 2)
			{
				result += a[i] * a[i + 1];
			}
		}
		else //���̳ʽ� ������ Ȧ
		{

		}
	}
	cout << result;
}