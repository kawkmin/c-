#include<iostream>
#include<algorithm>
using namespace std;

int N, M, an[500001], result[500001] = { 0, };

bool fd(int a)
{
	int start = 0,end=N-1;
	while (start <= end) //왜 an[start]<=an[end] 일 땐 시간초과지????
	{
		int mid = (start + end) / 2;
		if (an[mid] == a)
			return true;
		if (an[mid] > a)
			end = mid-1;
		else
			start = mid+1;
	}
	return false;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> an[i];
	}
	sort(an, an + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		if (fd(x))
			result[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cout << result[i]<<" ";
	}
}