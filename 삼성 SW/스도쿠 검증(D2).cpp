#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool tr2(int x, int y, vector<int>v[])
{
	vector<int> v4;
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			v4.push_back(v[i][j]);
		}
	}
	sort(v4.begin(), v4.begin());
	v4.erase(unique(v4.begin(), v4.end()), v4.end());
	if (v4.size() != 9)
		return false;

	return true;
}

bool tr(vector<int>v[])
{
	for (int i = 0; i < 9; i++)
	{
		vector<int> v2;
		vector<int> v3;
		for (int j = 0; j < 9; j++)
		{	
			v2.push_back(v[i][j]);
			v3.push_back(v[j][i]);
		}
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());
		v2.erase(unique(v2.begin(), v2.end()), v2.end());
		v3.erase(unique(v3.begin(), v3.end()), v3.end());
		if (v2.size() != 9 || v3.size() != 9)
			return false;
	}
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			if (!tr2(j, i,v))
			{
				return false;
			}
		}
	}
	return true;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int>v[10];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int a;
				cin >> a;
				v[i].push_back(a);
			}
		}
		if (tr(v))
		{		
			cout << "#" << test_case <<" 1"<< "\n";
		}
		else
			cout << "#" << test_case << " 0" << "\n";

	}
	return 0;
}


