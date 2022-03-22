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
//다른 방법으로 여는 괄호면 push 닫는 괄호면 pop을 해서 마지막으로 stack을 확인 후, 여는 괄호가 있으면 false 없으면
//push된 만큼 pop이 된 거니까, true
