#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> s;

void dfs(int x)
{		
	for (int i = x; i < s.size()-1; i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{			
			swap(s[i], s[j]);
			dfs(x+1);
			for (int k = 0; k < s.size(); k++)
				cout << s[k];
			cout << "\n";
			swap(s[j], s[i]);
			
		}
	}
}

int main()
{
	for (int i = 1; i < 4; i++)
	{
		char a = 'a'-1+i;
		s.push_back(a);
	}
	//dfs(0);
	sort(s.begin(), s.end());
	do {
		for (int k = 0; k < s.size(); k++)
			cout << s[k];
		cout << "\n";
	} while (next_permutation(s.begin(), s.end()));
}