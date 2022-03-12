#include<iostream>
#include<cmath>
using namespace std;

int main()		
{
	int n,a,b,q=1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			q = (q * a) % 10;
		}
		if (q == 0)
			q = 10;
		printf("%d\n", q);
		q = 1;
	}
}