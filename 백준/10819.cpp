#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> A;
int N;
int sum = 0;

int cal()
{
	int s = 0;
	for (int i = 0; i < N-1; i++)
	{
		s += abs(A[i] - A[i + 1]);
	}
	return s;
}

void Permutation(vector<int>& a, int start, int end)
{
	if (sum < cal())
		sum = cal();
	if (start == end-1)
		return;
	for (int i = start; i < end; i++)
	{
		swap(a[start], a[i]);
		Permutation(a, start + 1, end);
		swap(a[start], a[i]);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}
	Permutation(A, 0, N);
	cout << sum;

}