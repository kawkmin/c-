﻿#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 98765
using namespace std;
int n, m;
int dist[101][101];
int a[101][101];
int dx[4] = { 1,0,0,-1 }, dy[4] = { 0,-1,1,0 };

int dijkstra() 
{
    priority_queue<pair<int, pair<int, int> > > pq; //비용, (x,y)
    dist[1][1] = 0;
    pq.push(make_pair(0, make_pair(1, 1)));

    while (!pq.empty()) 
    {
        int nowd = -pq.top().first; // pq는 높은 수를 우선순위로 해서
        int nowx = pq.top().second.first;
        int nowy = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) 
        {
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];
            if (nx <1 || nx >m || ny < 1 || ny<1 || ny >n) 
                continue;

            if (dist[nx][ny] > dist[nowx][nowy] + a[nx][ny]) 
            {
                dist[nx][ny] = dist[nowx][nowy] + a[nx][ny];
                pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
            }
        }
    }

    return dist[m][n];
}

int main() 
{
  /*  6 6
        001111
        010000
        001111
        110001
        011010
        100010*/
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &a[i][j]);
            dist[i][j] = INF;
        }
    }
    printf("%d", dijkstra());
}