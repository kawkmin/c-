#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcs(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {

    int ans = 1;
    for (int i = 0; i < arr.size(); i++) {
        ans = lcs(ans, arr[i]);
    }

    return ans;
}

// int answer = 1;
//int era[101] = { 0, };
//int solution(vector<int> arr) { 최대 공약수 공식을 잘 몰랐음
//    for (int i = 2; i < 100; i++)
//    {
//        if (era[i] == 1)
//            continue;
//        era[i] = i;
//        for (int j = i + i; j <= 100; j += i)
//            era[j] = 1;
//    }
//    vector<int> erav;
//    for (int i = 2; i < 101; i++)
//        if (era[i] > 1)
//            erav.push_back(i);
//
//    int x = 0;
//    sort(arr.begin(), arr.end());
//    while (x != erav.size())
//    {
//        if (erav[x] > arr[0])
//            break;
//        for (int i = 0; i < arr.size(); i++)
//        {
//            if (arr[i] % erav[x]==0)
//            {
//                if (i == arr.size() - 1)
//                {
//                    answer *= erav[x];
//                    for (int j = 0; j < arr.size(); j++)
//                        arr[j] /= erav[x];
//                    x = 0;
//                }
//                continue;
//            }
//            else
//            {
//                x++;
//                break;
//            }
//        }
//
//    }
//    for (int i = 0; i < arr.size(); i++)
//        answer *= arr[i];
//    return answer;
//}

//int visit[123456789] = { 0, };
//
//int solution(vector<int> arr) {
//    int answer = 0;
//    int size = arr.size();
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 1; j < 1000000; j++)
//            visit[arr[i] * j]++;
//    }
//    for (int i = 0; i < 123456789; i++)
//    {
//        if (visit[i] == size)
//            return i;
//    }
//}

int main()
{
    vector<int> as = { 12, 32, 45, 67, 72 };
    solution(as);
}