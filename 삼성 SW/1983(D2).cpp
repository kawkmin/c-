#include <iostream>
#include<algorithm>
using namespace std;

int main() 
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		double a[101];
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			double x, y, z;
			cin >> x >> y >> z;
			a[i] = x * 0.35 + y * 0.45 + z * 0.2;
		}
		double temp = a[K-1];
		sort(a, a + N);
		string result;
		for (int i = 0; i < N; i++)
		{
			if (temp == a[i])
			{
				if (i < (N / 10))
					result = "D0";
				else if (i < (N / 10) * 2)
					result = "C-";
				else if (i < (N / 10) * 3)
					result = "C0";
				else if (i < (N / 10) * 4)
					result = "C+";
				else if (i < (N / 10) * 5)
					result = "B-";
				else if (i < (N / 10) * 6)
					result = "B0";
				else if (i < (N / 10) * 7)
					result = "B+";
				else if (i < (N / 10) * 8)
					result = "A-";
				else if (i < (N / 10) * 9)
					result = "A0";
				else if (i <N)
					result = "A+";
			break;
			}
		}
		cout << "#" << test_case << " " <<result<<"\n";
	}
	
}