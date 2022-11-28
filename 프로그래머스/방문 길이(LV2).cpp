#include <string>
#include<vector>
#include<set>
#include<iostream>
using namespace std;

int solution(string dirs) {
	int answer = 0;
	vector<pair<int, int>> v;
	v.push_back({ 0,0 });
	int cnt = 0;
	set<pair<pair<int,int>,pair<int,int>>> s;
	for (int i = 0; i < dirs.length(); i++)
	{
		int y = v.back().first;
		int x = v.back().second;
		switch (dirs[i])
		{
		case 'U':
			if (y < 5 )
			{
				v.push_back({ y + 1,x });
				if (s.find({ {y,x},{y + 1,x} }) == s.end() && s.find({ {y + 1,x},{y ,x} }) == s.end())
				{
					s.insert({ {y,x},{y + 1,x} });
					s.insert({ {y + 1,x},{y ,x} });
					cnt++;
				}
			}
			break;

		case 'D':
			if (y > -5)
			{
				v.push_back({ y - 1,x });
				if (s.find({ {y,x}, { y - 1, x } }) == s.end() && s.find({ {y - 1,x}, { y, x } }) == s.end())
				{
					s.insert({ {y,x}, { y - 1, x } });
					s.insert({ {y - 1,x}, { y, x } });
					cnt++;
				}
			}
			break;
		case 'R':
			if (x < 5 )
			{
				v.push_back({ y,x + 1 });
				if (s.find({ {y,x}, { y, x + 1 } }) == s.end() && s.find({ {y,x + 1}, { y, x } }) == s.end())
				{
					s.insert({ {y,x}, { y, x + 1 } });
					s.insert({ {y,x + 1}, { y, x } });
					cnt++;
				}
			}
			break;
		case 'L':
			if (x > -5 )
			{
				v.push_back({ y,x - 1 });
				if (s.find({ {y,x},{ y, x - 1 } }) == s.end() && s.find({ {y,x - 1},{ y, x } }) == s.end())
				{
					s.insert({ {y,x},{ y, x - 1 } });
					s.insert({ {y,x - 1},{ y, x } });
					cnt++;
				}
			}
			break;
		}
	}
	return cnt;
}

int main()
{
	cout<<solution("ULURRDLLU");

}