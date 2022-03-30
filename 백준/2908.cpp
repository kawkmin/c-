#include <iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	char temp;
	temp = s1[0];
	s1[0] = s1[2];
	s1[2] = temp;
	temp = s2[0];
	s2[0] = s2[2];
	s2[2] = temp;
	int x = stoi(s1);
	int y = stoi(s2);
	if (x > y)
		cout << x;
	else
		cout << y;
	
}
