#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	sort(arr, arr + 10, /*greater<>()*/);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

}