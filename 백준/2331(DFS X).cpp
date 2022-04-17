#include<iostream>
#include<string>
#include<vector>
using namespace std;

string D[10000];

bool already(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (D[i] == D[x])
			return false;
	}
	return true;
}

int main()
{
	int P;
	int i = 1,a=0;
	cin >> D[0] >> P;
	while (1)
	{
		int x=0;
		for (int j = 0; j < D[i - 1].length(); j++)
		{
			int z = 1;
			int y = D[i - 1][j]-'0';
			for (int k = 0; k < P; k++)
			{
				z *= y;
			}
			x += z;
		}	
		D[i] = to_string(x);
		if (!already(i))
		{
			string temp = to_string(x);
			while (1)
			{
				if (D[a] == temp)
					break;
				a++;
			}
			break;
		}
		i++;
	}
	cout << a;
}
