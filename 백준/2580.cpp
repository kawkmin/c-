#include<iostream>

using namespace std;
int sdock[10][10];

bool istrue(int y,int x,int a)
{
	for (int i = 0; i < 9; i++)
	{
		if (sdock[y][i] == a || sdock[i][x] == a)
			return false;
	}
	if (y < 3 && x < 3)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (sdock[i][j] == a)
					return false;
	}
	//for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
	//	for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
	//		if (sdock[i][j] == a) return false;
	else if (y < 3 && x < 6)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 3; j < 6; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 3 && x < 9)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 6; j < 9; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 6 && x < 3)
	{
		for (int i = 3; i < 6; i++)
			for (int j = 0; j < 3; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 6 && x < 6)
	{
		for (int i = 3; i < 6; i++)
			for (int j = 3; j < 6; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 6 && x < 9)
	{
		for (int i = 3; i < 6; i++)
			for (int j = 6; j < 9; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 9 && x < 3)
	{
		for (int i = 6; i < 9; i++)
			for (int j = 0; j < 3; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 9 && x < 6)
	{
		for (int i = 6; i < 9; i++)
			for (int j = 3; j < 6; j++)
				if (sdock[i][j] == a)
					return false;
	}
	else if (y < 9 && x < 9)
	{
		for (int i = 6; i < 9; i++)
			for (int j = 6; j < 9; j++)
				if (sdock[i][j] == a)
					return false;
	}
	return true;
}

void dfs(int y,int x)
{

	if (x == 9) 
	{ 
		y++; 
		x = 0; 
	}

	if (y == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sdock[i][j] << ' ';
			}
			cout << "\n";
		}
		exit(0);
	}

	if (sdock[y][x] != 0) 
	{
		dfs(y, x + 1);
		return;
	}

	for (int i = 1; i <= 9; i++) 
	{
		if (istrue(y, x, i))
		{
			sdock[y][x] = i;
			dfs(y, x + 1);
			sdock[y][x] = 0;
		}
	}
}

int main() 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sdock[i][j];
		}
    }
	dfs(0, 0);

	
}