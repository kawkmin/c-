#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int N, B, C, z;
	long long result = 0;
	vector<int> A;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> z;
		A.push_back(z);
	}
	cin >> B >> C;
	result = N;
	for (int i = 0; i < N; i++)
	{
		 A[i] -= B;
		if (A[i] > 0)
		{
			result+= ceil((double)A[i] / C);
		}
	}
	cout << result;
}