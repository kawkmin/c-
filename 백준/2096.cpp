#include<iostream>

using namespace std;

int N, dpmax[3], dpmin[3],MAX,MIN,a[3];

int main() //무조건 배열안에 저장한 상태로 진행할려고 했음
{
	cin >> N;
	for (int i = 0; i < 3; i++)
	{
		cin >> dpmax[i];
		dpmin[i] = dpmax[i];
	}
	for (int i = 1; i < N; i++)
	{
		cin >> a[0] >> a[1] >> a[2];

		int temp0 = dpmax[0];
		int temp1 = dpmax[1];
		int temp2 = dpmax[2];

		dpmax[0] = max(temp0, temp1) + a[0];
		dpmax[1] = max(max(temp0, temp1), temp2) + a[1];
		dpmax[2] = max(temp1, temp2) + a[2];
		
		temp0 = dpmin[0];
		temp1 = dpmin[1];
		temp2 = dpmin[2];

		dpmin[0] = min(temp0, temp1) + a[0];
		dpmin[1] = min(min(temp0, temp1), temp2) + a[1];
		dpmin[2] = min(temp1, temp2) + a[2];
	}
	MAX = max(max(dpmax[0], dpmax[1]), dpmax[2]);
	MIN = min(min(dpmin[0], dpmin[1]), dpmin[2]);
	cout << MAX<<" "<<MIN;

}