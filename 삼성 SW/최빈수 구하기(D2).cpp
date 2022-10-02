#include <iostream>
using namespace std;


int main() 
{
	
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int a[101] = { 0, };
		int test;
		cin >> test;
		for (int i = 0; i < 1000; i++)
		{
			int x;
			cin >> x;
			a[x]++;
		}
		int MAX = 0,index=0;
		for (int i = 0; i < 100; i++)
		{
			if (MAX <= a[i])
			{
				MAX = a[i];
				index = i;
			}
		}
		cout << "#" << test << " " <<index<<"\n";
	}
	
}