#include<iostream>

using namespace std;

int number = 100001;
int a[100001];

void primeNumbersieve()
{
	for (int i = 2; i < number; i++)
		a[i] = i;
	for (int i = 2; i < number; i++)
	{
		if (a[i] == 0) continue;
		for (int j = i + i; j < number; j += i) //배수를 제거하는걸 0으로서 표시
		{
			a[j] = 0;
		}
	}
	for (int i = 2; i < number; i++)
	{
		if (a[i] != 0) printf("%d ", a[i]);
	}
}

int main()
{
	primeNumbersieve();
}