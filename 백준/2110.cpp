#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> x;

int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int f;
		cin >> f;
		x.push_back(f);
	}
	sort(x.begin(), x.end());
	int start = 1, end = x[N - 1] - x[0];
	int cnt = 0, mid, result = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		int a = x[0];
		for (int i = 1; i < N; i++)
		{
			if (x[i] - a >= mid)
			{
				cnt++;
				a = x[i];
			}
		}
		if (cnt >= C - 1)
		{
			cnt = 0;
			result = mid;
			start = mid + 1;
		}
		else
		{
			cnt = 0;
			end = mid - 1;
		}
	}
	cout << result;
}