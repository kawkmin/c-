#include <iostream>
#include<vector>
using namespace std;

vector<int>W[11];
int N;
int ma = 987654321;
int visit[11];

void tsp(int start,int value,int depth,int x)
{
	if (depth == N - 1)
	{
        if (W[start][x] > 0)
        {
            value += W[start][x];
            if (ma > value)
                ma = value;
        }
		return;
    }
    visit[start] = true;
    for (int i = 0; i < W[start].size(); i++)
    {
        int y = W[start][i];
        if (!visit[i]&&y>0)
        {  
            tsp(i, value + y, depth + 1,x);
            visit[i] = false;           //�̰� ���ؼ�  ��ð� ��������...????????? 
        }                               // �ι�°���� ù��°�� �湮�� ���� �湮 ���ϰԵǾ���� 
    }                                   
}                                       
                                        
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            W[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
	{
		tsp(i, 0, 0, i);
        visit[i] = false;
    }
    cout << ma;
}