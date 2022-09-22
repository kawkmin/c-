#include<iostream>

using namespace std;

int a[2200][2200];

int N,cnt1,cnt2,cnt3;

void cut(int y,int x,int n)
{
	int temp = a[y][x];
	
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (temp != a[i][j])
			{
				n /= 3;
				for (int k = y; k < y + n * 3; k += n)
				{
					for (int z = x; z < x+n * 3; z += n)
					{
						cut(k, z,n);
					}
				}
				return;
			}
		}
	}
	switch (temp)
	{
	case -1:cnt1++;
		break;
	case 0:cnt2++;
		break;
	case 1:cnt3++;
		break;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	}
	cut(0, 0, N);
	cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;
}