#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		stack<char> s;
		string cs;
		int result = 0;
		int x = 0; 
		int y = 0;
		bool b = true;
		cin >> cs;
		for (int j = 0; j < cs.length(); j++)
		{
			s.push(cs[j]);
		}
		int size = s.size();
		for (int k = 0; k < size; k++)
		{

			if (s.top() == '(') x++;
			else if (s.top() == ')') y++;
			if (x > y)
			{
				cout << "NO \n";
				b = false;
				break;
			}
			s.pop();
		}
		if (b) {
			if (x-y == 0)
				cout << "YES \n";
			else
				cout << "NO \n";
		}
	}
}
