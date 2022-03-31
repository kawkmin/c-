#include<iostream>

using namespace std;

int main()
{
	long long a[10001];
	long long K, N,x=0;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i];
	}
	while (1)
	{
		x++;
		long long count = 0;
		for (int i = 0; i < K; i++)
		{
			count += a[i] / x;
			if (count > N)
				continue;
		}
		if (count < N)
		{
			x--;
			break;
		}
	}
	cout << x;
}
