#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//3��� ������ = ���ڸ��� ���� ���� ���� 3�� ������߸� �Ѵ�. 

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