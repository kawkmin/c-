#include <iostream>
#include<algorithm>

using namespace std;

int N, n[500001], M, m[500001], cnt;


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &m[i]);
	}
	sort(n, n + N);
	for (int i = 0; i < M; i++)
	{
		cnt = 0;
		int x = lower_bound(n, n + N, m[i])-n; //�ּ��� �̸��� ����Ű�� ������ -�迭
		int y = upper_bound(n, n + N, m[i])-n;
		for (int i = x; i < y; i++)
			cnt++;
		cout << cnt << " ";
	}
}
