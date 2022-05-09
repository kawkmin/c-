#include <iostream>

using namespace std;

int N, S, a[21], cnt = 0;

//void dfs(int start,int val)              
//{                                            �� ������ ���Ұ͵� dfs��Ű�⿡ �ð��ʰ�.
//    for (int i = start; i < N; i++)          �� 
//    {                                        ��
//        val += a[i];                         ��
//        if (val == S)                        ��
//        {                                    ��
//            cnt++;                           ��
//            return;                          ��
//        }                                    ��
//        dfs(start + 1, val);                 ��
//        val = 0;                             ��
//    }                                        ��
//}                                            ��
                                               
void dfs(int depth,int val)
{
    if (depth == N)
        return;
    if (val + a[depth] == S)
        cnt++;
    dfs(depth + 1, val);                 //������ ���Ѵ�
    dfs(depth + 1, val + a[depth]);      //������ �Ѵ�
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