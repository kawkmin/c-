#include<iostream>
using namespace std;

void swap(int& num1, int& num2)
{
	int t = num1;
	num1 = num2;
	num2 = t;
}
void quicksort(int* data, int start, int end)
{
	if (start >= end) return;

	int key = start;
	int i = start + 1, j = end;
	while (i <= j)//엇갈릴 때 까지 반복
	{
		while (i <= end && data[i] <= data[key]) i++;
		while (j > start && data[j] >= data[key]) j--;
		if (i > j)//엇갈린거임
		{
			swap(data[j], data[key]);
		}
		else
		{
			swap(data[i], data[j]);
		}
	}
	quicksort(data, start, j - 1);
	quicksort(data, j + 1, end);
}

int main()
{
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	quicksort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}