#include<iostream>

using namespace std;

int d(int x)
{
	if (x == 1)return 1;
	if (x == 2)return 1;
	return d(x - 1) + d(x - 2);
}

int main()
{
	printf("%d", d(50));
}