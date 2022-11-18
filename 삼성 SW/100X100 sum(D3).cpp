#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;
		int arr[101][101];
	
		int dsum1 = 0;
		int dsum2 = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
			}
		}
		int result = 0;
		for (int i = 0; i < 100; i++)
		{
			int rowsum = 0;
			int columnsum = 0;
			for (int j = 0; j < 100; j++)
			{
				columnsum += arr[j][i];
				rowsum += arr[i][j];
				if (i == j) dsum1 += arr[i][j];
				if (j + i == 99) dsum2 += arr[i][j];
			}
			result = max(max(rowsum,columnsum), result);
		}
		result = max(max(dsum1, dsum2), result);
		cout << "#" << T <<" "<< result<<"\n";
	}
	return 0;
}

