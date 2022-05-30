#include<iostream>

using namespace std;

int N, M, m[11],su=0;

int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		m[x] = 1;
	}
	int num[8],temp=N,x=100000,index=0,cnt=0,cnt2;

	while (temp)					//5000일 때 그냥 5만 넣어짐
	{
		if (temp / x)
		{
			num[index] = temp / x;
			temp -= num[index] * x;
			index++;
		}
		x /= 10;
	}
	
	for (int i = 0; i < index; i++)
	{
		cnt++;
		int a = num[i], b = num[i], c;
		if (m[a])
		{
			while (a < 9 && b>1)
			{
				a++;
				b--;
				if (!m[a])
				{
					c = a;
					break;
				}
				else if (!m[b])
				{
					c = b;
					break;
				}
				c = 0;
			}
		}
		else
			c = a;
		for (int j = 1; j < index - i; j++)
			c *= 10;
		su += c;
	}
	while (su != N)
	{
		if (su > N)
			su -= 1;
		else
			su += 1;
		cnt++;
	}
	cnt = min(cnt, abs(N - 100));
	cout <<cnt;
}