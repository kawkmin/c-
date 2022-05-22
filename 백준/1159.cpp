#include <iostream>
using namespace std;

int main()
{
	int a[26];
	for (int i = 0; i < 26; i++)
		a[i] = 0;
	
	int predaja = 26;
	char player;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		string name;
		cin >> name;
		a[name[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		player = ' ';
		if (a[i] >= 5) 
		{
			player = i + 'a';
			cout << player;
		}
		else predaja--;
	}

	if (!predaja) cout << "PREDAJA";

}