#include<iostream>
using namespace std;

void swap(int& num1, int& num2)
{
	int t = num1;
	num1 = num2;
	num2 = t;
}

int main()
{
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	for (int i = 0; i < 10; i++)
	{
		int min = 11, index;
		for (int j = i; j < 10; j++)
		{
			if (arr[j] < min)
			{
				index = j;
				min = arr[j];
			}
			
		}
		swap(arr[index], arr[i]);
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}