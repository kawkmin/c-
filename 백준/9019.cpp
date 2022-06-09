#include <iostream>
#include<string>
#include<queue>

using namespace std;
int visit[100000];

int D(int x)
{
	int result = x * 2;						//(x*2)%10000
	if (result > 9999)						
		result %= 10000;					
	return result;							
}

int S(int x)
{
	int result = x - 1;						//x-1<0 ? 9999: x-1
	if (x == 0)
		result = 9999;
	return result;
}

int L(int x)
{
	string stringx = to_string(x);
	if (x < 10)
		stringx = '0' + stringx;		//(x%1000)*10+(x/1000)
	if (x < 100)						//내가 왜 이렇게 했찌???
		stringx = '0' + stringx;
	if (x < 1000)
		stringx = '0' + stringx;
	int d1 = stringx[0] - '0';
	x -= d1 * 1000;
	x *= 10;
	int result = x + d1;
	return result;
}

int R(int x)
{
	string stringx = to_string(x);	//(x/10)+(1000*(x%10))
	if (x < 10)						//내가 왜 이렇게 했찌????>????./ 
		stringx = '0' + stringx;
	if (x < 100)
		stringx = '0' + stringx;
	if (x < 1000)
		stringx = '0' + stringx;
	int d4 = stringx[3] - '0';
	x /= 10;
	int result = d4 * 1000 + x;
	return result;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A >> B;
		for (int i = 0; i < 10000; i++)
			visit[i] = 0;
		queue<pair<string, int>> q;
		q.push({ "", A });			 //
		visit[A] = 1;				 //
		while (!q.empty())
		{
			string fronts = q.front().first;
			int result = q.front().second;
			q.pop();
			if (result == B)
			{
				cout << fronts << "\n";
				break;
			}
			else
			{
				int l = L(result);
				int d = D(result);
				int s = S(result);
				int r = R(result);
				if (d >= 0 && !visit[d])
				{
					q.push({ fronts + 'D',d });
					visit[d] = 1;
				}
				if (s >= 0 && !visit[s])
				{
					q.push({ fronts + 'S',s });
					visit[s] = 1;
				}
				if (l >= 0 && !visit[l])
				{
					q.push({ fronts + 'L',l });
					visit[l] = 1;
				}
				if (r >= 0 && !visit[r])
				{
					q.push({ fronts + 'R',r });
					visit[r] = 1;
				}
			}
		}
	}
	//cout << D(T) << "\n" << S(T) << "\n" << L(T) << "\n" << R(T) << "\n";
}