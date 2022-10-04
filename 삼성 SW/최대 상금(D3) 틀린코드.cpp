#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(int argc, char** argv) //32888 안됨
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string N;
        int C, cnt = 0;
        cin >> N >> C;
        int MAX, index;
        bool b = false;
        for (int i = 0; i < N.size() - 1; i++)
        {
            for (int j = i + 1; j < N.size(); j++)
                if (N[i] == N[j])
                    b = true;
            if (b)
                break;
        }

        for (int i = 0; i < N.size() - 1; i++)
        {
            MAX = N[i];
            for (int j = N.size() - 1; j > i; j--)
            {
                if (MAX < N[j])
                {
                    MAX = N[j];
                    index = j;
                }
            }
            if (MAX != N[i])
            {
                cnt++;
                swap(N[i], N[index]);
            }
            if (cnt == C)
                break;
        }
        if (cnt != C && C % 2 == 1)
        {
            if (!b)
                swap(N[N.size() - 1], N[N.size() - 2]);
        }

        cout << "#" << test_case << " " << N << "\n";

    }
    return 0;
}