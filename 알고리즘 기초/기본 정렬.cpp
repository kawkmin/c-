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
		for (int j = i+1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}