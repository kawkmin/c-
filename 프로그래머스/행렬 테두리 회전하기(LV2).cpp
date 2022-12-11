#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(101, vector<int>(101));
    int index = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            arr[i][j] = index++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][1];
        int y1 = queries[i][0];
        int x2 = queries[i][3];
        int y2 = queries[i][2];

        int x = x1;
        int y = y1;
        queue<int> q;

        int MIN = 10001;
        for (int i = x; i <= x2; i++)
        {
            q.push(arr[y][i]);
        }
        x++;
        for (; x <= x2; x++)
        {
            arr[y][x] = q.front();
            MIN = min(MIN, q.front());
            q.pop();
        }
        x--;
        y++;
        for (; y <= y2; y++)
        {
            q.push(arr[y][x]);
            arr[y][x] = q.front();
            MIN = min(MIN, q.front());
            q.pop();
        }
        y--;
        x--;
        for (; x >= x1; x--)
        {
            q.push(arr[y][x]);
            arr[y][x] = q.front();
            MIN = min(MIN, q.front());
            q.pop();
        }
        x++;
        y--;
        for (; y >= y1; y--)
        {
            if (y != y1)
                q.push(arr[y][x]);
            arr[y][x] = q.front();
            MIN = min(MIN, q.front());
            q.pop();
        }
        answer.push_back(MIN);
    }

    return answer;
}