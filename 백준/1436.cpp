#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N,title=0,k=0;
	int x[100001];
	cin >> N;
	for (long long i = 666; i < 20000000; i++)
	{
		int cnt = 0;
		string s = to_string(i);
		for (int j = 0; j < s.length(); j++)
		{
			if (j + 2 < s.length() && s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6')
			{
				x[k] = i;
				k++;
				break;
			}
		}
		if (k > N-1)
			break;
	}
	cout << x[N - 1];
}