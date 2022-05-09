#include <iostream>

using namespace std;

int N, S, a[21], cnt = 0;

//void dfs(int start,int val)              
//{                                            ㅇ 포함을 안할것도 dfs시키기에 시간초과.
//    for (int i = start; i < N; i++)          ㅇ 
//    {                                        ㅇ
//        val += a[i];                         ㅇ
//        if (val == S)                        ㅇ
//        {                                    ㅇ
//            cnt++;                           ㅇ
//            return;                          ㅇ
//        }                                    ㅇ
//        dfs(start + 1, val);                 ㅇ
//        val = 0;                             ㅇ
//    }                                        ㅇ
//}                                            ㅇ
                                               
void dfs(int depth,int val)
{
    if (depth == N)
        return;
    if (val + a[depth] == S)
        cnt++;
    dfs(depth + 1, val);                 //포함을 안한다
    dfs(depth + 1, val + a[depth]);      //포함을 한다
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << cnt;
}