#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int test_case;
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int dump;
        cin >> dump;
        int box[101];
        for (int i = 0; i < 100; i++)
        {
            cin >> box[i];
        }
        for (int i = 0; i < dump; i++)
        {
            sort(box, box + 100);
            box[0]++;
            box[99]--;
        }
        sort(box, box + 100);
        cout << "#" << test_case << " " << box[99] - box[0] << "\n";
    }
}