#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,sum=0;
	cin >> N;
	int a[1001],result[1001];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N; i++)
	{
		sum = sum + a[i];
		result[i] = sum;
	}
	sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += result[i];
	}
	cout << sum;
}