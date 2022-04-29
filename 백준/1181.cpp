#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool comp(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main()
{
	int N;
	cin >> N;
	string s[20001];
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	sort(s, s + N,comp);
	/*
	int slen[20001];
	for (int i = 0; i < N; i++)
	{
		slen[i] = s[i].length();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1-i; j++)
		{
			if (slen[j] > slen[j + 1])
			{
				int temp = slen[j];
				slen[j] = slen[j + 1]; 시간초과
				slen[j + 1] = temp;
				string t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	} */

	for (int i = 0; i < N; i++)
	{
		if(s[i]!=s[i+1])
			cout << s[i]<<"\n";
	}
}