#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
        return cities.size() * 5;

    int answer = 0;
    vector<string> v;
    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities[i].size(); j++)
        {
            if (cities[i][j] < 'a')
                cities[i][j] += 'a' - 'A';
        }
        int cnt = 5;
        v.push_back(cities[i]);
        for (int j = 0; j < v.size()-1; j++)
        {
            if (v[j] == cities[i])
            {
                v.erase(v.begin() + j);
                cnt = 1;
                break;
            }
        }
        if (v.size() > cacheSize)
            v.erase(v.begin());
        answer += cnt;
    }
    return answer;
}