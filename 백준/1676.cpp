#include<iostream>

using namespace std;
int N;

int main()
{
	cin >> N;
	int cnt = 0;
	for (int i =5; i <= N; i*=5)
	{
		cnt += (N / i);
	}
	cout << cnt;
}