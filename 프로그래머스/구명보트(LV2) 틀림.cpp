#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int index = 0;
    while (index < people.size())
    {
        if (people[index] + people[people.size() - 1] <= limit) 
        {
            answer++;
            index++;
        }
        else
        {
            answer++;
        }
        people.pop_back();
    }
    return answer;
}
/* 시간 적합성 오류

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {  //최대한 큰 값을 구할 땐 뒤에서 부터 확인한다.
    int answer = 0;
    sort(people.begin(), people.end());
     while (people.size() > 0)
    {
       for(int i=people.size()-1;i>=0;i--)
       {
           if(i==0)
           {
               answer++;
               people.erase(people.begin());
               break;
           }
           if(people[0]+people[i]<=limit)
           {
               answer++;
               people.erase(people.begin()+i);
               people.erase(people.begin());
               break;
           }
       }
    }
    return answer;
}
*/


/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
            right--;
            answer++;
        }
        else
        {
            right--;
            answer++;
        }
    }
    return answer;
}
*/