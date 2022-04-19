#include<iostream>

using namespace std;

typedef struct adc
{
    int a[10000];
    char b[10000];
}S_ABC;

void call_you(S_ABC *abc_struct_2)
{
    cout << "sadfasd";
}

int main()
{
    S_ABC abc_struct_1;
    call_you(&abc_struct_1);
}