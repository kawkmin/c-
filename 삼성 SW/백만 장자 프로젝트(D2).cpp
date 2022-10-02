#include <iostream>
using namespace std;

int a[1000001];

int main() 
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long sum = 0;
		long long MAX = 0;
		long long N,ans=0;
		cin >> N;
		for (long long i = 0; i < N; i++)
		{
			cin >> a[i];
			if (a[i] > MAX) 
			{
				MAX = a[i]; 
				ans = i;
			}
		}

		for (long long i = 0; i < N; i++)
		{
			if (i == ans)
			{
				MAX = 0;
				for (long long j = ans+1; j < N; j++)
				{
					if (a[j] > MAX)
					{
						MAX = a[j];
						ans = j;
					}
				}
				continue;
			}
			sum += MAX - a[i];
			//뒤에서 부터 계산하면 쉽게 된다...
		}
		cout << "#" << test_case << " " << sum<<"\n";
	}
	
}