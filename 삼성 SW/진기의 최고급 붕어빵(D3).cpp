#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M, K, cnt = 0;
        vector<int> arr;
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int time = 0;
        int customer = 0;
        bool b = true;
        while (customer != N && b)
        {
            if (time != 0 && time % M == 0)
            {
                cnt += K;
            }
            if (arr[customer] == time)
            {
                while (arr[customer] == time)
                {
                    if (!cnt)
                    {
                        b = false;
                    }
                    else
                        cnt--;
                    customer++;
                }
            }
            time++;
        }
        if (b)
            cout << "#" << test_case << " Possible" << "\n";
        else
            cout << "#" << test_case << " Impossible" << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}