#include <iostream>

using namespace std;

int main() 
{
	long long n;
	int L;
	cin >> n >> L;

	long long s = -1, e = -1;

	for (int i = L; i <= 100; i++) 
	{
		if (i % 2 == 1) 
		{
			if (n % i == 0) 
			{
				e = n / i + i / 2;
				s = n / i - i / 2;
				break;
			}
		}
		else 
		{
			if (n % i == i / 2)
			{
				e = n / i + i / 2;
				s = n / i - i / 2 + 1;
				break;
			}

		}
	}
	if (s < 0) 
		cout << -1 << endl;
	
	else 
	{
		for (int i = s; i <= e; i++) {
			cout << i << " ";
		}
		cout << endl;
	}
}