#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> m;

int main()
{
	int N,M,ans=0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		m.insert({ s, i });
	}
	for (int i = 0; i < M; i++)
	{
		string str2;
		cin >> str2;
		if (m[str2])
			ans++;
	}
	cout << ans;
}

