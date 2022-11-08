#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<char> v;
	map<string,int> m;
	string s;
	int ans = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s[i]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		string s = "";
		for (int j = i; j < v.size(); j++)
		{
			s += v[j];
			if (m[s]) continue;
			m[s] = 1;
			ans++;
		}
	}
	cout << ans;
}

