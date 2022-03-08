#include<iostream>
#include<vector>
#define NUMBER 12

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
int tree[4 * NUMBER];

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int main()
{
	
}
