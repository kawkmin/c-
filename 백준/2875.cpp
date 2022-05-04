#include<iostream>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++)
	{
		if (N >= 2 * M)
			N--;
		else
			M--;
	}
	cout << min(N/2, M );
}