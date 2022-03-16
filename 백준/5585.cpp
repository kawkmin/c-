#include<iostream>

using namespace std;

int main()
{
	int money, count = 0, pay = 1000;
	cin >> money;
	pay -= money;
	count += pay / 500;
	pay %= 500;
	count += pay / 100;
	pay %= 100;
	count += pay / 50;
	pay %= 50;
	count += pay / 10;
	pay %= 10;
	count += pay / 5;
	pay %= 5;
	count += pay;
	cout << count;
}
