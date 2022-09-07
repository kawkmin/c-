#include <iostream>
using namespace std;

int main() 
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int sum = 0;
		int a;
		for (int i = 0; i < 10; i++)
		{
			cin >> a;
			if (a % 2 == 1)
				sum += a;
		}
		cout <<"#"<<test_case<<" "<<sum<<"\n";
	}
	
}