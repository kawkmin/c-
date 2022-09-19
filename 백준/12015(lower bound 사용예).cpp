#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	vector<int> v = { 1000001 };
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a > v.back())
			v.push_back(a);
		else
		{
			v[lower_bound(v.begin(), v.end(), a) - v.begin()] = a;
		}
	}
	cout << v.size();
}