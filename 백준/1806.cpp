#include <iostream>
#include<algorithm>

using namespace std;
int n[100001];
int N, S;

int main() 
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> n[i];
	
	int high = 0,low=0,sum=n[0],cnt=100001;
	while (high >= low && high < N)
	{
		if (sum < S)
		{
			sum += n[++high];
		}
		else
		{
			cnt = min(cnt, high - low + 1);
			sum -= n[low++];
		}
	}
	if (cnt == 100001)
		cout << 0;
	else
		cout << cnt;
}