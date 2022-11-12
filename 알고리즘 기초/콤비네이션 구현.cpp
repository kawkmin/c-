#include <iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;


int main()
{
    string s = "ABCD";
    map<string, int> m;

    do {
        vector<char> v;
        for (int i = 0; i < s.size(); i++)
        {
            v.push_back(s[i]);
            string temp = "";
            for (int j = 0; j < v.size(); j++)
                temp += v[j];
            sort(temp.begin(), temp.end());
            if (!m[temp])
            {
                m[temp] = 1;
                cout << temp << "\n";
            }
        }
    } while (next_permutation(s.begin(), s.end()));
}