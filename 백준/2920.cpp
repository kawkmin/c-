#include <iostream>
#include<cstring>
using namespace std;

int main() 
{
	char da[9] = { 'c','d','e','f','g','a','b','C'};
	string s;
	int a[9];
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 8; i++)
	{
		s += da[a[i] - 1];
	}
	if (s == "cdefgabC")
		s = "ascending";
	else if (s == "Cbagfedc")
		s = "descending";
	else
		s = "mixed";
	cout << s;
}
