#include<iostream>
#include<queue>
#include<string>
using namespace std;

int deci[10000],visit[10000];

void d()
{
	for (int i = 2; i < 10000; i++)
	{
		deci[i] = i;
	}
	for (int i = 2; i < 10000; i++)
	{
		if (deci[i] == 0)
			continue;
		for (int j = 2; i*j <10000; j++)
		{
			deci[i*j] = 0;
		}
	}
}

int main()
{
	d();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 1000; j < 10000; j++)
			visit[j] = 0;
		queue<pair<string, int>> q;
		int y,b,result=-1;
		string x,a;
		cin >> x >> y;
		q.push(make_pair(x, 0));
		visit[stoi(x)] = 1;
		while (!q.empty())
		{
			a = q.front().first;
			b = q.front().second;
			q.pop();
			if (a == to_string(y))
			{
				result = b;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					string temp = a; //안해주면 계속 바뀜
					temp[i] = j+'0';
					int xy = stoi(temp);
					if (xy >= 1000 && xy < 10000 && deci[xy] && !visit[xy])
					{
						visit[xy] = 1;
						q.push(make_pair(to_string(xy), b + 1));						
					}
				}
			}
		}
		if (result!=-1)
			cout << result << "\n";
		else
			cout << "Impossible" << "\n";
	}
}