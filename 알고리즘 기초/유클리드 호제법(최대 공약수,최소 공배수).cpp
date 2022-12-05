#include<iostream>
using namespace std;
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "두 수의 최대공약수는 : " << gcd(a, b) << " 입니다" << endl;
	cout << "두 수의 최소공배수는 : " << (a * b) / gcd(a, b) << " 입니다" << endl;
}
