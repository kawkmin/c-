#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int N,M,avg=0,a[1001];
	cin >> N;
	double score=0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	M = v[N - 1];
	for (int i = 0; i < N; i++)
	{
		double x = (double)v[i] / (double)M;
		score += x * 100;
	}

	cout << score / (double)N;

}
