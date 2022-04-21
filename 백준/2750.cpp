#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int x[1001];
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	sort(x, x + N);
	for (int i = 0; i < N; i++)
	{
		cout<< x[i]<<"\n";
	}
}