#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int a[300001],P;

void DFS(int num)
{
	a[num]++;
	if (a[num] == 3) //2�� �ϸ� �ݺ��Ǵ� �������� �޺κ��� a[�޺κ�]=1 �̵ȴ�.
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
