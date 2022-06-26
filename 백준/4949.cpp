#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() 
{
	while (1) 
	{
		stack<char>s; 
		string str;
		getline(cin, str); 
		bool b = true; 
		if (str.length() == 1 && str[0] == '.')
			break;
		for (int i = 0; i < str.length(); i++) 
		{
			if (str[i] == '(' || str[i] == '[') 
				s.push(str[i]);

			if (str[i] == ')') 
			{
				if (s.empty() || s.top() == '[')
					b = false;
				else 
					s.pop();
			}
			if (str[i] == ']') 
			{
				if (s.empty() || s.top() == '(')
					b = false;
				else 
					s.pop();
			}
		}
		if (s.empty() && b)
			cout << "yes" << '\n';
		else 
			cout << "no" << '\n';
	}
}