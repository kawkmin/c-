#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//3배수 판정법 = 각자리의 수를 더한 것이 3의 배수여야만 한다. 

using namespace std;

int main()
{	
	vector<int> v;
	string N;
	int sum=0;
	cin >> N;
	bool b = false;
	for (int i = 0; i < N.length(); i++)
	{
		if (N[i] == '0')
		{
			b = true;
			break;
		}
	}
	if (b)
	{
		for (int i = 0; i < N.length(); i++)
		{
			int x = N[i] - 48;
			v.push_back(x);
			sum += v[i];
		}
		if (sum % 3 == 0)
		{
			sort(v.begin(), v.end(), greater<int>());
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
		}
		else
			cout << "-1";
	}
	else
		cout << "-1";
	
}