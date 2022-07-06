#include<iostream>
#include<string>
#include<map>
using namespace std;
string spocket[100001];
map<string, int> pocket;

int main()
{
	int N, M;
	cin >> N >> M;

	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= N; i++)
	{
		cin >> spocket[i];
		pocket.insert({ spocket[i],i });
	}
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (isdigit(s[0]))
			cout << spocket[stoi(s)] << "\n";	
		else
			cout << pocket.find(s)->second << "\n";
	}
	/*for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (s[0]<10)
			cout << pocket[stoi(s)]<<"\n";
		else
		{
			for (int i = 1; i <= N; i++)
				if (pocket[i] == s)
				{
					cout << i << "\n";
					break;
				}
		}
	} ÇØ½¬¸Ê x */
}