#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
	int n;
	int map[11][11] = { 0, };
	cin >> n;
	int cnt = 1;
	int state = 0;
	int count = n;
	int x = 0;
	int y = 0;
	while (count>0)
	{
		if (state == 0)
		{
			for (int i = 0; i < count; i++)
			{
				map[y][x] = cnt;
				cnt++;
				x++;
			}
			x--;
			state = 1;
			count--;
			if (cnt == n) break;
		}
		if (state == 1)
		{
			for (int i = 0; i < count; i++)
			{
				y++;
				map[y][x] = cnt;
				cnt++;
			}
			state = 2;
			if (cnt == n) break;
		}
		if (state == 2)
		{
			for (int i = 0; i < count; i++)
			{
				x--;
				map[y][x] = cnt;
				cnt++;
			}
			state = 3;
			count--;
			if (cnt == n) break;
		}
		if (state == 3)
		{
			for (int i = 0; i < count; i++)
			{
				y--;
				map[y][x] = cnt;
				cnt++;
			}
			x++;
			state = 0;
			if (cnt == n) break;
		}		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << map[i][j]<<" ";
		cout << '\n';
	}
	
}