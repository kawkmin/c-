#include <iostream>
#include<cstring>
using namespace std;

int main()
{
	int N,score=0,result=0;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		score = 0;
		result = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'O')
			{
				score+=1;
			}
			else
			{
				score = 0;
			}
			result += score;
		}
		
		cout << result<<'\n';
	}
	
}
