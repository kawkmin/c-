#include<iostream>
#include<string>
using namespace std;

int N, M, m[11];

bool check(int x)
{
	string s = to_string(x);
	for (int i = 0; i < s.length(); i++)
	{
		if (m[s[i] - '0'])
			return 0;
	}
	return 1;
}

int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		m[x] = 1;
	}
	int mm = abs(N-100);
	for (int i = 0; i <= 1000000; i++)
	{
		if (check(i))
		{
			int z= abs(N - i) + to_string(i).length();
			mm = min(mm, z);
		}
	}
	
	cout << mm;
}