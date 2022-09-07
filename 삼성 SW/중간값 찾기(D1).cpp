#include <iostream>
#include<algorithm>
using namespace std;

int main() 
{
	int test_case;
	int T;
	cin >> T;
	int a[200];
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a[test_case];
	}
	sort(a, a + T);
	if (T % 2 == 0)
		cout << a[T / 2 + 1];
	else
		cout << a[T / 2];
}