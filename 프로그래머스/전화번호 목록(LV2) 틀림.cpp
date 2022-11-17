#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> map1;
    for (int i = 0; i < phone_book.size(); i++)
        map1[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            string phone_number = phone_book[i].substr(0, j + 1);
            if (map1[phone_number])
                return false;
        }
    }
    return true;
}