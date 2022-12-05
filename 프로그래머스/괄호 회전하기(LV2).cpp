#include <string>
#include <vector>
#include<stack>
using namespace std;

bool valid(vector<char> s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (st.size() == 0)
		{
			st.push(s[i]);
		}
		else
		{
			if (st.top() == '{') {
				if (s[i] == '}')
					st.pop();
				else
					st.push(s[i]);
			}

			else if (st.top() == '(') {
				if (s[i] == ')')
					st.pop();
				else
					st.push(s[i]);
			}
			else if (st.top() == '[') {
				if (s[i] == ']')
					st.pop();
				else
					st.push(s[i]);
			}
		}
	}
	if (st.size() != 0)
		return false;
	return true;
}

int solution(string s) {
	int answer = 0;
	vector<char> temps;
	for (int i = 0; i < s.length(); i++)
		temps.push_back(s[i]);

	for (int i = 0; i < s.length(); i++)
	{
		char temp = temps[0];
		temps.erase(temps.begin());
		temps.push_back(temp);
		if (valid(temps))
			answer++;
	}
	return answer;
}

int main() {
	solution("[)(]");
}