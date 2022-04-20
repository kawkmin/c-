#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{

	string s,temp;
	string S[1001];
	cin >> s;
	int len = s.length();
	
	for (int i = 0; i < len; i++)
	{
		temp = s.substr(i, len);
		S[i] = temp;
	}
	sort(S,S+len);

	for (int i = 0; i < s.length(); i++)
	{
		cout << S[i]<<"\n";
	}

}