#include<iostream>
#include<string>

using namespace std;

int main()
{	
	int alpha[26] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		alpha[s[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i]<<" ";
	}
}