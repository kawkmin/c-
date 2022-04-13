#include<iostream>

using namespace std;

int main()
{
	int S, E, M,s=0,e=0,m=0,day=0;
	cin >> E >> S >> M;
	while (1)
	{
		if (  e == E && s == S && m == M)
			break;
		e++;
		s++;
		m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m= 1;
		day++;
	}
	cout << day;
}