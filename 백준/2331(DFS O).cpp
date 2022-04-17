#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int a[300001],P;

void DFS(int num)
{
	a[num]++;
	if (a[num] == 3) //2로 하면 반복되는 구간에서 뒷부분은 a[뒷부분]=1 이된다.
		return;
	int sum = 0;
	while (num)
	{
		sum += (int)pow((num % 10), P);
		num /= 10;
	}
	DFS(sum);
}

int main()
{
	int A,x=0;
	cin >> A >> P;
	DFS(A);
	for (int i = 0; i < 300001; i++)
	{
		if (a[i] == 1)
		{
			x++;
		}
	}
	cout << x;
}
