#include<iostream>

using namespace std;

int number = 8;
int size;
int sorted[8];

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}
void mergesort(int a[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergesort(a, m, middle);
		mergesort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main()
{
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergesort(arr, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
}