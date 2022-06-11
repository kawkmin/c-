#include <iostream>

using namespace std;

int main()
{
	int A, B, N,a;
	cin >> A >> B >> N;
	for (int i = 0; i <= N; i++)
	{
		a = A / B;
		A = A%B * 10;
	}
	cout << a;
}