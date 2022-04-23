#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int result = 1;
	int bird = 1;

	while (1)
	{
		if (N - bird >= 0)
			N -= bird;
		else
		{
			bird = 1;
			N -= bird;
		}
		if (N == 0)
			break;

		result++;
		bird++;
	}
	cout << result;
}