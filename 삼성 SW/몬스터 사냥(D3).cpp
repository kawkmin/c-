#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int D, L, N;
        double result = 0;
        cin >> D >> L >> N;
        for (int i = 0; i < N; i++)
        {
            result += D * (1 + L * i * 0.01);
        }
        cout << "#" << test_case << " " << (int)result << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}