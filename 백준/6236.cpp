#include<iostream>

using namespace std;
int a[1000001];

int main()
{
	int N, M,sum=0;
	cin >> N >> M;
	int start=1;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		sum += a[i];
		start = max(start, a[i]); // 이분탐색 할 때 시작점 기준 한번은 실행 할 수 있게끔 하자
	}
	int end = sum;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int tempsum = mid,cnt=1;
		for (int i = 0; i < N; i++)
		{
			if (tempsum - a[i] < 0)
			{
				tempsum = mid;
				cnt++;
			}
			tempsum -= a[i];
		}
		if (cnt <= M)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << start;
}
