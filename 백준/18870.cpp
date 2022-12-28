#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        temp[i] = v[i];
    }

    sort(temp.begin(), temp.end()); 

    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin() << ' ';
    }
}