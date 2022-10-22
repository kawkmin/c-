#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    int arr[100]={0,}; //초기화 해주는게 오류 잘 안남
    cin>>T;
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            arr[i*j]=1;
        }
    }
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int x;
        cin>>x;
        if(arr[x]==1)
            cout<<"#"<<test_case<<" Yes\n";
        else
            cout<<"#"<<test_case<<" No\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}