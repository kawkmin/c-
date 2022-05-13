#include <iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int  N, n[2][100001];
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> n[0][i];
		for (int i = 0; i < N; i++)
			cin >> n[1][i];
		int xx = 1;
		int yy = 0;
		int x = n[0][0];
		int y = n[1][0];
		for (int i = 1; i < N; i++)
		{
			if ( n[xx][i] + n[yy][i+1] < n[xx][i+1])
			{
				continue;
			}
			x += n[xx][i];
			swap(xx, yy);
		}
		xx = 1;
		yy = 0;
		for (int i = 1; i < N; i++)
		{
			if (n[yy][i] + n[xx][i+1] < n[yy][i+1])
			{
				continue;
			}		
			y += n[yy][i];
			swap(xx, yy);
		}
		if (x > y)
			cout << x << "\n";
		else
			cout << y << "\n";
	}
}
